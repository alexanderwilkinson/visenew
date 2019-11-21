/** @file project.h
 *  @brief denotes a VISE project
 *  @author Abhishek Dutta
 *  @date 15 Nov. 2019
 */
#ifndef PROJECT_H
#define PROJECT_H

#include "search_engine.h"
#include "vise_util.h"
#include "relja_retrival/relja_retrival.h"

#include <memory>
#include <thread>

#include <boost/filesystem.hpp>

namespace vise {
  enum class SEARCH_ENGINE_ID { RELJA_RETRIVAL, _RESERVED_FOR_FUTURE };
  enum class PROJECT_STATE { UNKNOWN, INIT, INDEX, SEARCH };

  class project {
  public:
    project(std::string pname,
            std::map<std::string, std::string> const &conf);
    project(project const &p);
    ~project();
    void index();

  private:
    std::string d_pname;
    boost::filesystem::path d_storedir;
    boost::filesystem::path d_datadir;
    boost::filesystem::path d_pconf_fn;

    const std::map<std::string, std::string> d_conf;  // VISE application configuration
    std::map<std::string, std::string> d_pconf;       // project configuration
    std::unique_ptr<vise::search_engine> d_search_engine;

    std::thread d_index_thread;
  };
}
#endif
