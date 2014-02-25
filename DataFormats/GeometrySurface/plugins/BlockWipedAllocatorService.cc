#include "FWCore/PluginManager/interface/ModuleDef.h"
#include "FWCore/ServiceRegistry/interface/ServiceMaker.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"

#include "DataFormats/GeometrySurface/interface/BlockWipedAllocator.h"
#include <iostream>


#include "DataFormats/GeometrySurface/interface/ReferenceCounted.h"


namespace {
  struct Dumper {
    void visit(BlockWipedAllocator const& alloc) const {
      BlockWipedAllocator::Stat sa1 = alloc.stat();
      std::cout << "Alloc for size " << sa1.typeSize
		<< ": " << sa1.blockSize
		<< ", " << sa1.currentOccupancy
		<< "/" << sa1.currentAvailable
		<< ", " << sa1.totalAvailable
		<< "/" << sa1.nBlocks
		<< ", " << sa1.alive
		<< std::endl;
    }
    
  };
  
}

/**  manage the allocator
 */
class BlockWipedAllocatorService {
private:
  bool m_useAlloc;
  bool m_silent;
  bool m_dump;
  int  m_clearFreq;
  BlockWipedPool pool;
public:
  BlockWipedAllocatorService(const edm::ParameterSet & iConfig,
			     edm::ActivityRegistry & iAR ) :
    pool( std::max(256,iConfig.getUntrackedParameter<int>("blockSize",1024)),
	  std::max(256,iConfig.getUntrackedParameter<int>("recyclerSize",4096))
	  ) {
    
    m_useAlloc = iConfig.getUntrackedParameter<bool>("usePoolAllocator",false);
    m_silent = iConfig.getUntrackedParameter<bool>("silent",true);
    m_dump = iConfig.getUntrackedParameter<bool>("dumpEachModule",false);
    m_clearFreq = std::max(1,iConfig.getUntrackedParameter<int>("clearFrequency",20));

    blockWipedPool(&pool);
    if (m_useAlloc) BlockWipedPoolAllocated::usePool();
    iAR.watchPreSource(this,&BlockWipedAllocatorService::preSource);
    iAR.watchPreProcessEvent(this,&BlockWipedAllocatorService::preEventProcessing);
    iAR.watchPostEndJob(this,&BlockWipedAllocatorService::postEndJob);
    iAR.watchPreModule(this,&BlockWipedAllocatorService::preModule);
    iAR.watchPostModule(this,&BlockWipedAllocatorService::postModule);
  }

  // wipe the workspace before each event
  void preEventProcessing(const edm::EventID&, const edm::Timestamp&) { wiper();}

  // nope event-principal deleted in source
  void preSource() {
   // wiper();
  }

  void dump() {
    if (m_silent) return;
    std::cout << "ReferenceCounted stat"<< std::endl;
    std::cout << "still alive/referenced " 
	      << ReferenceCountedPoolAllocated::s_alive
	      << "/" << ReferenceCountedPoolAllocated::s_referenced
	      << std::endl;

    std::cout << "BlockAllocator stat"<< std::endl;
    std::cout << "still alive " << BlockWipedPoolAllocated::s_alive << std::endl;
    Dumper dumper;
    blockWipedPool().visit(dumper);
  }


  void wiper() {
    dump();
    blockWipedPool().wipe();
    // blockWipedPool().clear();  // try to crash
    {
       static int c=0;
       c++;
       if (m_clearFreq==c) {
	 blockWipedPool().clear();
	 c=0;
       }
    }

  }
 
  // wipe before each module (no, obj in event....)
  void preModule(const edm::ModuleDescription& desc){
    blockWipedPool().wipe(false);
  }

  void postModule(const edm::ModuleDescription& desc){
    if (m_dump) dump();
    }

  // final stat
  void postEndJob() {
    wiper();
  }
  
};



DEFINE_FWK_SERVICE(BlockWipedAllocatorService);
