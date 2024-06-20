#ifndef METEOREVACUATIONSYSTEM_H_INCLUDED
#define METEOREVACUATIONSYSTEM_H_INCLUDED
#endif // METEOREVACUATIONSYSTEM_H_INCLUDED_H_INCLUDED
#include<string>;
using namespace std;
double GetMetorSize() {
 double meteorSizeInMeters;
 do {
 cout << "Enter Meteore Size in Meters: ";
 cin >> meteorSizeInMeters;
 if (meteorSizeInMeters <= 0) {
 cout << "Invalid Meteor Size. Enter again" << endl;
 }
 } while (meteorSizeInMeters <= 0);
 return meteorSizeInMeters;
}
double GetMeteorDistanceFromEarthInMiles() {
 double meteorDistanceFromEarthInMiles;
 do {
 cout << "Enter Meteore Distance From Earth in Miles: ";
 cin >> meteorDistanceFromEarthInMiles;
 if (meteorDistanceFromEarthInMiles <= 0) {
 cout << "Invalid Miles. Enter again" << endl;
 }
 } while (meteorDistanceFromEarthInMiles <= 0);
 return meteorDistanceFromEarthInMiles;
}
double CalculateMeteorSpeed(double size) {
 return size * 120; //as per instruction document.//MPH.
}
bool IsMeteorTrackable(double meteorSize, double meteorDistanceFromEarthInMiles) {
 bool trackable = false;
 if (meteorSize >= 3 && meteorDistanceFromEarthInMiles <= 440) {
 trackable = true;
 }
 else if (meteorSize >= 2 && meteorDistanceFromEarthInMiles <= 330) {
 trackable = true;
 }
 else if (meteorSize >= 1 && meteorDistanceFromEarthInMiles <= 220) {
 trackable = true;
 }
 else if (meteorDistanceFromEarthInMiles <= 110) {
 trackable = true;
 }
 return trackable;
}
double CalculateMeteorTimeToImpact(double speedOfMeteor, double currentDistanceFromEarth) {
 return (currentDistanceFromEarth / speedOfMeteor) * 60;//speed is in MPH. So time will be hours.
We xply with 60 to get minutes.
}
double CalculateMissileInterceptionRange(double meteorSpeedInMPH, double
initialDistanceOfMeteorFromEarth) {
 //The given: When the missile is launhced, it will reach meteor 3.4 minutes.
 //In 3.4 minutes how distance in Miles will meteor cover?
 double distanceTravelledByMeteor = 3.4 * meteorSpeedInMPH / 60;
 if ((initialDistanceOfMeteorFromEarth - distanceTravelledByMeteor) < 0) {
 return 0;
 }
 else {
 return (initialDistanceOfMeteorFromEarth - distanceTravelledByMeteor);
 }
}
string GetMDSStatus(double meteorDistanceFromEarth, double timeToImpact, double
missileInterceptRange, bool isMeteorTrackable) {
 string mdsStatus;
 if (!isMeteorTrackable) {
 mdsStatus = "";
 }
 else if (missileInterceptRange > 0 && missileInterceptRange < meteorDistanceFromEarth)
 {
 mdsStatus = "Missile Intercept Probable";
 }
 else {
 mdsStatus = "Missile Intercept Not Possible - Earth Impact in " + to_string(timeToImpact) + "
minutes";
 }
 if (mdsStatus == "Missile Intercept Probable" && missileInterceptRange >= meteorDistanceFromEarth)
{
 mdsStatus = "Missile Intercept Occurred";
 }
 return mdsStatus;
}
string GetMeteorStatus(bool isMeteorTrackable) {
 string meteorStatus;
 if (isMeteorTrackable) {
 meteorStatus = "Meteor Inbound";
 }
 else {
 meteorStatus = "Meteor Cannot be tracked by the System";
 }
 return meteorStatus;
}
void ShowOutput(double meteorDiameters, double meteorDistanceFromEarth, double meteorSpeed,
double timeToImpact,
 double missileInterceptRange, bool isMeteorTrackable, string mdsStatus, string meteorStatus, string
evacuationStatus) {
 cout << "Meteor Data" << endl;
 cout << "\tDiameter in Meters: " << meteorDiameters << " Meters" << endl;
 cout << "\tDistance from Earth: " << meteorDistanceFromEarth << " Miles" << endl;
 cout << "\tSpeed in Mph: " << meteorSpeed << " MPH" << endl;
 cout << "\tTime to Impact: " << timeToImpact << " Minutes" << endl;
 cout << endl;
 cout << "Engagement Data" << endl;
 missileInterceptRange = isMeteorTrackable ? missileInterceptRange : 0.0;
 cout << "\tMissile Interception Range: " << missileInterceptRange << " Miles" << endl;
 cout << "\tMDS Status: " << mdsStatus << endl;
 cout << endl;
 cout << "\t Meteore Status:" << meteorStatus << endl;
 cout << "\tMeteore Trackable (Extra Printing): " << isMeteorTrackable << endl;
 cout << "\tEvacuation Status: "<< evacuationStatus <<endl;
}
string GetEvacuationStatus(double TimeToImpact){
 string Evacuation_status;
 if (TimeToImpact<45){
 Evacuation_status="Evacuation CANNOT BE COMPLETED";
 }
 else if (TimeToImpact>45 && TimeToImpact<=90){
 Evacuation_status="Evacuation is possible";
 }
 else if (TimeToImpact>90){
 Evacuation_status="Evacuation is Probable";
 }
 return Evacuation_status;
}
