/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     |
    \\  /    A nd           | Copyright (C) 2011-2013 OpenFOAM Foundation
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

Class
    Foam::noRadiation

Description
    Dummy radiation model for 'none' option

SourceFiles
    noRadiation.C

\*---------------------------------------------------------------------------*/

#ifndef noRadiation_H
#define noRadiation_H

#include "filmRadiationModel.H"
#include "volFieldsFwd.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{
namespace regionModels
{
namespace surfaceFilmModels
{

/*---------------------------------------------------------------------------*\
                         Class noRadiation Declaration
\*---------------------------------------------------------------------------*/

class noRadiation
:
    public filmRadiationModel
{
private:

    // Private member functions

        //- Disallow default bitwise copy construct
        noRadiation(const noRadiation&);

        //- Disallow default bitwise assignment
        void operator=(const noRadiation&);


public:

    //- Runtime type information
    TypeName("none");


    // Constructors

        //- Construct from surface film model and dictionary
        noRadiation
        (
            surfaceFilmModel& owner,
            const dictionary& dict
        );


    //- Destructor
    virtual ~noRadiation();


    // Member Functions

        // Evolution

            //- Correct
            virtual void correct();

            //- Return the radiation sensible enthalpy source
            virtual tmp<volScalarField> Shs();
            //- Return const access to the radiation sensible enthalpy source
            virtual tmp<volScalarField> ShsConst() const; // kvm
};


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace surfaceFilmModels
} // End namespace regionModels
} // End namespace Foam

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //
