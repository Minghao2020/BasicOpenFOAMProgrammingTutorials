/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     | Website:  https://openfoam.org
    \\  /    A nd           | Copyright (C) 2021 OpenFOAM Foundation
     \\/     M anipulation  |
-------------------------------------------------------------------------------
License
    This file is part of OpenFOAM.

    OpenFOAM is free software: you can redistribute it and/or modify it
    under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    OpenFOAM is distributed in the hope that it will be useful, but WITHOUT
    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
    FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
    for more details.

    You should have received a copy of the GNU General Public License
    along with OpenFOAM.  If not, see <http://www.gnu.org/licenses/>.

Application
    OFProgramming01_helloOpenFOAM

Description

\*---------------------------------------------------------------------------*/

// fvCFD.H includes many foundamental header files 
// One can use "locate fvCFD.H" to figure out the file path, i.e.
// /home/minghao/OpenFOAM/OpenFOAM-7/src/finiteVolume/cfdTools/general/include/fvCFD.H
// Another note is that namespcae Foam is also defined in fvCFD.H
#include "fvCFD.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

int main(int argc, char *argv[])
{
    // These header files are not needed for this demo
    /*
    #include "setRootCase.H"
    #include "createTime.H"
    #include "createMesh.H"
    #include "createFields.H"
    */
    // * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

    // Standard c++ way of printing message
    // Note the std is a namespace
    std::cout << "Hello OpenFOAM !!!    (printed by std::cout)" << std::endl;

    // OpenFOAM way of printing message
    // Note the namespace Foam is defined in fvCFD.H 
    // #ifndef namespaceFoam
    // #define namespaceFoam
    //     using namespace Foam;
    // #endif
    Info<< "Hello OpenFOAM !!!    (printed by Foam::Info)" << nl << "nl for next line" << endl;
    
    Info<< "End\n" << endl;

    return 0;
}


// ************************************************************************* //
