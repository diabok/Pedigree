//
// Created by marek on 01.11.23.
//

#ifndef TWORCZOSC_MILOSZA_INDIVIDUALENTRY_H
#define TWORCZOSC_MILOSZA_INDIVIDUALENTRY_H

#include <string>

struct IndividualEntry {
    IndividualId *id;
    IndividualId *father_id;
    IndividualId *mother_id;
};

#endif //TWORCZOSC_MILOSZA_INDIVIDUALENTRY_H
