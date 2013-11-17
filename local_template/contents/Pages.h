/**
 * Tatoblog  A blog platform in C++
 *
 * Copyright (C) 2013 Allan Simon <allan.simon@supinfo.com> 
 * See accompanying file COPYING.TXT file for licensing details.
 *
 * @category Tatoblog
 * @author   Allan Simon <allan.simon@supinfo.com> 
 * @package  Contents
 *
 */

#ifndef CPPCMS_SKEL_CONTENTS_PAGES_H
#define CPPCMS_SKEL_CONTENTS_PAGES_H

#include "cppcms_skel/contents/content.h"

namespace contents {
namespace pages {

/**
 * Base content for every action of Pages controller
 *
 */
struct Pages : public BaseContent {
};

/**
 * @struct Homepage
 * Content used by the homepage
 */
struct Homepage : public Pages {

    Homepage() {
    }

};


} // end of namespace pages
} //end of namespace contents

#endif
