/** @file relja_retrival.h
 *  @brief Interface to the visual search engine developed by
 *         Relja Arandjelovic during his DPhil / Postdoc at
 *         the Visual Geometry Group, Department of Engineering
 *         Science, University of Oxford in 2014.
 *  @author Abhishek Dutta
 *  @date 20 Nov. 2019
 */
#ifndef RELJA_RETRIVAL_H
#define RELJA_RETRIVAL_H

#include "vise/search_engine.h"

#include "build_index.h"
#include "embedder.h"
#include "feat_standard.h"
#include "hamming_embedder.h"
#include "mpi_queue.h"
#include "train_assign.h"
#include "train_descs.h"
#include "train_cluster.h"
#include "train_hamming.h"
#include "util.h"

#include <iostream>
#include <map>
#include <string>
#include <sstream>

#include <boost/filesystem.hpp>

namespace vise {
  class relja_retrival:public search_engine {
  public:
    relja_retrival(std::map<std::string, std::string> const &pconf);
    ~relja_retrival();
    void index() override;
    void search() override;
  private:
    void extract_train_descriptors();
    void create_file_list();

    const std::map<std::string, std::string> d_pconf;
    const boost::filesystem::path d_storedir;
    const boost::filesystem::path d_datadir;
    boost::filesystem::path d_filelist_fn;
    boost::filesystem::path d_traindesc_fn;
  };
}
#endif
