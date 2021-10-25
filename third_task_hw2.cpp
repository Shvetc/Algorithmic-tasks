#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <queue>

void mergeSequence (std::vector<int> thevecf, std::vector<int> thevecl, std::vector<int>& theMergeVec) {
    auto iter_vecf = thevecf.begin();
    auto iter_vecl = thevecl.begin();
    int acurentNumb;
    while (iter_vecf != thevecf.end() && iter_vecl != thevecl.end()) {
        acurentNumb = std::min (*iter_vecf, *iter_vecl);
        iter_vecf = (acurentNumb == *iter_vecf) ? ++iter_vecf : iter_vecf;
        iter_vecl = (acurentNumb == *iter_vecl) ? ++iter_vecl : iter_vecl;
        std::cout << "aCurrentNumb : " << acurentNumb  << std::endl;
        theMergeVec.push_back(acurentNumb);
    }
    if (iter_vecf == thevecf.end() && iter_vecl != thevecl.end()) {
        while (iter_vecl != thevecl.end()) {
        theMergeVec.push_back(*iter_vecl);
        iter_vecl++;
        }
    }
    else if (iter_vecl == thevecl.end() && iter_vecf != thevecf.end()) {
         while (iter_vecf != thevecf.end()) {
         theMergeVec.push_back(*iter_vecf);
         iter_vecf++;
         }
    }
}

void mergeNSequence (std::vector<std::vector<int>> theVecSec, int firstP, int lastP, std::vector<int>& theoutputvec) {
    if (firstP == lastP) {
        for (int i = 0; i < theVecSec[firstP].size(); ++i) {
            theoutputvec.push_back (theVecSec[firstP][i]);
        }
        return;
    }

    if ((lastP - firstP) == 1) {
        mergeSequence (theVecSec[firstP], theVecSec[lastP], theoutputvec);
        return;
    }

    std::vector<int> aVecF (theVecSec[firstP].size());
    std::vector<int> aVecL (theVecSec[lastP].size());

    mergeNSequence(theVecSec, firstP, (firstP + lastP) / 2, aVecF);
    mergeNSequence(theVecSec, (firstP + lastP) / 2 + 1, lastP, aVecL);

    mergeSequence (aVecF, aVecL, theoutputvec);
    
}

int main()
{   
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> aveSeq (n, std::vector<int> (m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            std::cin >> aveSeq[i][j];
        }
    }
    std::vector<int> amergeVec;
    mergeNSequence (aveSeq, 0,  n - 1, amergeVec);
    for (int i = 0; i < amergeVec.size(); ++i) {
        std::cout << amergeVec[i] << " ";
    }

    return 0;
}
