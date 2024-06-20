// MeteorDefenseSystem.cpp : This file contains the 'main' function. Program execution begins and ends
there.
//
#include <iostream>
#include "MeteorEvacuationSystem.h"
#include<iomanip>
using namespace std;
int main()
{
 cout << setprecision(2) << fixed << showpoint ;
 double sizeOfMeteorInMeters = GetMetorSize();
 double initiaDistanceOfMeteorFromEarthInMiles = GetMeteorDistanceFromEarthInMiles();
 double meteorSpeed = CalculateMeteorSpeed(sizeOfMeteorInMeters);
 double missileInterceptRange = CalculateMissileInterceptionRange(meteorSpeed,
initiaDistanceOfMeteorFromEarthInMiles);//interception
 //range will not change. It only needs to be calculated when identified the meteor.
 int minutesPassed = 0;
 double remainingDistanceOfMeteorFromEarthInMiles;
 do
 {
 double distanceCoveredInTime = meteorSpeed * minutesPassed/60;
 bool isMeteorTrackable = IsMeteorTrackable(sizeOfMeteorInMeters,
remainingDistanceOfMeteorFromEarthInMiles);
 remainingDistanceOfMeteorFromEarthInMiles = initiaDistanceOfMeteorFromEarthInMiles -
distanceCoveredInTime;
 cout<<"Missile Intercept Range "<<missileInterceptRange<<endl;
 double meteoreTimeToImpactInMinutes = CalculateMeteorTimeToImpact(meteorSpeed,
remainingDistanceOfMeteorFromEarthInMiles);
 string EvacuationStatus=GetEvacuationStatus(meteoreTimeToImpactInMinutes);
 string mdsStatus = GetMDSStatus(remainingDistanceOfMeteorFromEarthInMiles,
meteoreTimeToImpactInMinutes, missileInterceptRange, isMeteorTrackable);
 string meteorStatus = GetMeteorStatus(isMeteorTrackable);
 if(missileInterceptRange < remainingDistanceOfMeteorFromEarthInMiles)
 {
 ShowOutput(sizeOfMeteorInMeters, remainingDistanceOfMeteorFromEarthInMiles,
meteorSpeed, meteoreTimeToImpactInMinutes, missileInterceptRange,
 isMeteorTrackable, mdsStatus, meteorStatus,EvacuationStatus);
 }
 else if(remainingDistanceOfMeteorFromEarthInMiles <=0)//meteor hit before missile intercept
 {
 ShowOutput(sizeOfMeteorInMeters, 0, meteorSpeed, 0, missileInterceptRange,
 isMeteorTrackable, mdsStatus, "Earth Impacted", EvacuationStatus);
 }
 else {
 ShowOutput(sizeOfMeteorInMeters, 0, meteorSpeed, 0, missileInterceptRange,
 isMeteorTrackable, "Intercept", "Destroyed",EvacuationStatus);
 }
 minutesPassed++;
 cout<<endl;
 cout<<endl;
 cout<<endl;
 cin.get();
 }while(missileInterceptRange < remainingDistanceOfMeteorFromEarthInMiles);
 }
