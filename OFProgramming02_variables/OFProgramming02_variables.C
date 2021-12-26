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
    OFProgramming02_variables

Description
    Understand OpenFOAM variables types

    detailed coding style guide: 
        https://openfoam.org/dev/coding-style-guide/
    detailed Expressions syntax: 
        https://www.openfoam.com//documentation/guides/latest/doc/openfoam-guide-expression-syntax.html

\*---------------------------------------------------------------------------*/

#include "fvCFD.H"
#include "labelVector.H"
// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

int main(int argc, char *argv[])
{
    /*
    #include "setRootCase.H"
    #include "createTime.H"
    #include "createMesh.H"
    #include "createFields.H"
    */
    // * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

    // link: http://www.cfdyna.com/Home/of_Programming.html
    // OpenFOAM has implemented (inherited) few variables to suit the programming requirement.
    // label = integer (int in C++): the size of variable types in bytes are not explicitly defined in C++
    // scalar = float or double
    // word = single word (inherited rom C++ string object)
    // string = quoted text
    // list = array bounded by () e.g. (1 2 4 8)
    // prefixList = array of type 'prefix'e.g. labelList, wordList, scalarList
    Info<< "\n*Understand OpenFOAM modified variables" << endl;

    label a = 2; 
    scalar b = 0.5;
    word w = "a_single_word";
    string s = "a_quoted_string";

    Info<< "label(c++ int) a: " << a << nl 
        << "scalar(c++ double/float) b: " << b << nl 
        << "word w: " << w << nl << "string s: " << s << endl;


    // OpenFOAM programming guide Chap 2 and Appendix A.1
    // link: http://foam.sourceforge.net/docs/Guides-a4/ProgrammersGuide.pdf
    Info<< "\n*Understand tensor" << endl;
    
    // typedef Vector<scalar> vector;
    // https://cpp.openfoam.org/v9/classFoam_1_1Vector.html
    vector u1(1, 2, 3); 
    Vector<scalar> u2(1.1, 2.2, 3.3);

    // vector elements can be accessed by either x() y() z() functions or 0 1 2 index. 
    // It makes more scene to use x() y() z() in CFD
    Info<< "vector u1: " << u1 << nl 
        << "u1.x(): " << u1.x() << "; u1[0]: " << u1[0] << nl
        << "u1.y(): " << u1.y() << "; u1[1]: " << u1[1] << nl
        << "u1.z(): " << u1.z() << "; u1[2]: " << u1[2] << nl
        << "Vector<scalar>  u2: " << u2 << endl;
    
    // typedef Vector<label> labelVector
    labelVector lv1(4, 5, 6); 
    Vector<label> lv2(4.5, 5.5, 6.5); 

    // only take the integer part
    Info<< "labelVector lv1: " << lv1 << nl << "Vector<label> lv2: " << lv2 << endl;
    
    // typedef Tensor<scalar> tensor;
    // https://cpp.openfoam.org/v9/classFoam_1_1Tensor.html
    tensor T1(1, 2, 3, 4, 5, 6, 7, 8, 9); 
    Tensor<scalar> T2(u1, u1, u2); 

    // tensor elements can be accessed by xx() xy() xz()... functions
    Info<< "tensor T1: " << T1 << nl 
        << "T1.xx(): " << T1.xx() << "; T1.xy(): " << T1.xy() << "; T1.xz(): " << T1.xz() << nl
        << "return 1st vector T1.x(): " << T1.x() << nl
        << "T1.yx(): " << T1.yx() << "; T1.yy(): " << T1.yy() << "; T1.yz(): " << T1.yz() << nl
        << "return 2nd vector T1.y(): " << T1.y() << nl
        << "T1.zx(): " << T1.zx() << "; T1.zy(): " << T1.zy() << "; T1.zz(): " << T1.zz() << nl
        << "return 3rd vector T1.z(): " << T1.z() << endl;
    // show example of transpose and inverse functions
    Info<< "Tensor<scalar> T2: " << T2 << nl
        << "return transpose T2.T(): " << T2.T() << nl
        << "return inverse T2.inv(): " << T2.inv() << endl;


    // OpenFOAM programming guide Chap 2.2 and Appendix A.1
    // link: http://foam.sourceforge.net/docs/Guides-a4/ProgrammersGuide.pdf
    Info<< "\n*Understand algebraic tensor operations " << endl;
    Info<< "vector addition u1+u2: " << (u1 + u2) << nl
        << "scalar multiplication a*u1: " << a * u1 << nl 
        << "scalar multiplication b*u1: " << b * u1 << nl 
        << "outer product u1u2: " << (u1 * u2) << nl
        << "inner product u1.u2: " << (u1 & u2) << nl
        << "inner product u1.T1: " << (u1 & T1) << nl
        << "cross product u1xu2: " << (u1 ^ u2) << nl
        << endl;

    // pos(x): if x > 0: 1.0 else 0.0, 
    // pos0(x) : if x ≥ 0: 1.0 else 0.0
    // neg(x): if x < 0: 1.0 else 0.0
    // neg0(x): if x ≤ 0: 1.0 else 0.0
    // sign(x): if x is positive: 1.0 else if x is negative: -1.0
    Info<< "pos(0.5): " << pos(0.5) << nl
        << "pos(0.0): " << pos(0.0) << nl
        << "pos0(0.5): " << pos0(0.5) << nl
        << "pos0(0.0): " << pos0(0.0) << nl
        << "sign(0.5): " << sign(0.5) << nl
        << "sign(-0.5): " << sign(-0.5) << endl;

    // OpenFOAM programming guide Chap 2.3 and Appendix A.1
    // link: http://foam.sourceforge.net/docs/Guides-a4/ProgrammersGuide.pdf
    Info<< "\n*Understand dimensioned variables " << endl;

    // typedef dimensioned<scalar> dimensionedScalar;
    // https://cpp.openfoam.org/v9/classFoam_1_1dimensioned.html
    dimensionedScalar ds_T 
        (
            "ds_T",  // word
            dimensionSet(0,0,0,1,0,0,0),  // dimensions
            300  // value
        ); 
    dimensionedScalar ds_T1 
        (
            "ds_T1", 
            dimTemperature,  // defined in $FOAM_SRC/OpenFOAM/dimensionSet/dimensionSets.C
            b // L62: scalar b = 0.5; 
        ); 
    Info<< "dimensionedScalar ds_T: " << ds_T << nl
        << "ds_T.name(): " << ds_T.name() << nl
        << "ds_T.dimensions(): " << ds_T.dimensions() << nl
        << "ds_T.value(): " << ds_T.value() << endl;
    Info<< "dimensionedScalar ds_T1: " << ds_T1 << nl
        << "ds_T1.name(): " << ds_T1.name() << nl
        << "ds_T1.dimensions(): " << ds_T1.dimensions() << nl
        << "ds_T1.value(): " << ds_T1.value() << endl;

    dimensionedVector dv_U
    (
        "dv_U",
        dimVelocity,
        u1 // L77: vector u1(1, 2, 3); 
    );
    Info<< "dimensionedVector dv_U: " << dv_U << nl
        << "dv_U.name(): " << dv_U.name() << nl
        << "dv_U.dimensions(): " << dv_U.dimensions() << nl
        << "dv_U.value(): " << dv_U.value() << endl;    

    dimensionedTensor sigma
    (
        "sigma",
        dimensionSet(1, -1, -2, 0, 0, 0, 0),
        tensor (1e6, 0, 0, 0, 1e6, 0, 0, 0, 1e6)
    );
    Info<< "dimensionedTensor sigma: " << sigma << nl
        << "sigma.name(): " << sigma.name() << nl
        << "sigma.dimensions(): " << sigma.dimensions() << nl
        << "sigma.value(): " << sigma.value() << endl; 


    Info<< "End\n" << endl;

    return 0;
}


// ************************************************************************* //
