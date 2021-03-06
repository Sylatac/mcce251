#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "ipece.h"

extern IPECE_PRM ipece_prm;
extern BOX box;

float get_score(ATOMS atoms) {
    int ia;
    float score = 0;
    
    for (ia=0; ia<atoms.n; ia++) {
        if (fabs(atoms.array[ia].r[2]) < ipece_prm.half_mem_thickness)
        score += atoms.array[ia].score;
    }
    
    score += (1-box.buried_cylinder_axis[2]*box.buried_cylinder_axis[2]) * ipece_prm.axis_score_weight;
    return score;
}
