#ifndef SISTRIPCLUSTER_CLASSES_H
#define SISTRIPCLUSTER_CLASSES_H

#include "DataFormats/SiStripCluster/interface/SiStripClusterCollection.h"
#include "DataFormats/Common/interface/Wrapper.h"
#include <vector>
#include <map>
#include "DataFormats/Common/interface/LazyGetter.h"

namespace {
  struct dictionary {
    edm::Wrapper<SiStripClusterCollection> siStripClusterCollectionWrapper;
  };
}

#include "DataFormats/Common/interface/DetSetVector.h"
#include "DataFormats/Common/interface/DetSetVectorNew.h"
#include "DataFormats/Common/interface/Ref.h"
#include "DataFormats/SiStripCluster/interface/SiStripCluster.h"
#include "DataFormats/Common/interface/ContainerMask.h"
namespace {
  struct dictionary2 {
    edm::Wrapper< SiStripCluster > dummy0;
    edm::Wrapper< std::vector<SiStripCluster>  > dummy1;
    edm::Wrapper< edm::DetSet<SiStripCluster> > dummy2;
    edm::Wrapper< std::vector<edm::DetSet<SiStripCluster> > > dummy3;
    edm::Wrapper< edm::DetSetVector<SiStripCluster> > dummy4;
    edm::Wrapper< std::vector< std::vector < edm::DetSet<SiStripCluster> > > > dummy5;

    edm::Wrapper< edmNew::DetSetVector<SiStripCluster> > dummy4_bis;

    edm::ContainerMask<edmNew::DetSetVector<SiStripCluster> > dummy_cm1;
    edm::Wrapper<edm::ContainerMask<edmNew::DetSetVector<SiStripCluster> > > dummy_w_cm1;

    std::vector<edm::Ref<edmNew::DetSetVector<SiStripCluster>,SiStripCluster,edmNew::DetSetVector<SiStripCluster>::FindForDetSetVector> > dummy_v;
    edmNew::DetSetVector<edm::Ref<edmNew::DetSetVector<SiStripCluster>,SiStripCluster,edmNew::DetSetVector<SiStripCluster>::FindForDetSetVector> > dumm_dtvr;
    edm::Wrapper<edmNew::DetSetVector<edm::Ref<edmNew::DetSetVector<SiStripCluster>,SiStripCluster,edmNew::DetSetVector<SiStripCluster>::FindForDetSetVector> > > dumm_dtvr_w;

    std::vector<edm::Ref<edm::LazyGetter<SiStripCluster>,SiStripCluster,edm::FindValue<SiStripCluster> > > dsvr_v1;
    edmNew::DetSetVector<edm::Ref<edm::LazyGetter<SiStripCluster>,SiStripCluster,edm::FindValue<SiStripCluster> > > dsvr_1;
    edm::Wrapper<edmNew::DetSetVector<edm::Ref<edm::LazyGetter<SiStripCluster>,SiStripCluster,edm::FindValue<SiStripCluster> > > > dsvr_w2;
    
    edm::Ref<   edm::DetSetVector<SiStripCluster>, SiStripCluster, edm::refhelper::FindForDetSetVector<   SiStripCluster> >    refOld;
    edm::Ref<edmNew::DetSetVector<SiStripCluster>, SiStripCluster, edmNew::DetSetVector<SiStripCluster>::FindForDetSetVector > refNew;
  };
}

#include "boost/cstdint.hpp" 
#include "DataFormats/Common/interface/RefGetter.h"
namespace {
  struct dictionary3 {

    edm::Wrapper< edm::RegionIndex<SiStripCluster> > dummy7;
    edm::Wrapper< std::vector< edm::RegionIndex<SiStripCluster> > > dummy8;
    edm::Wrapper< edm::LazyGetter<SiStripCluster> > dummy9;
    edm::Wrapper< edm::Ref<edm::LazyGetter<SiStripCluster>,edm::RegionIndex<SiStripCluster>,edm::FindRegion<SiStripCluster> > > dummy10;
    edm::Wrapper< std::vector<edm::Ref<edm::LazyGetter<SiStripCluster>,edm::RegionIndex<SiStripCluster>,edm::FindRegion<SiStripCluster> > > > dummy12;
    edm::Wrapper< edm::RefGetter<SiStripCluster> > dummy13;
    edm::Wrapper< edm::Ref< edm::LazyGetter<SiStripCluster>, SiStripCluster, edm::FindValue<SiStripCluster> > > dummy14;
    
    edm::ContainerMask<edm::LazyGetter<SiStripCluster> > dummy_cm1;
    edm::Wrapper<edm::ContainerMask<edm::LazyGetter<SiStripCluster> > > dummy_w_cm1;
    edm::RefProd<edm::LazyGetter<SiStripCluster> > dummy_rp_l_ssc1;
  };
}

#endif // SISTRIPCLUSTER_CLASSES_H
