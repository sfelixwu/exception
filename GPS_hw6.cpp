
#include "GPS.h"

GPS_DD::GPS_DD()
{
  this->latitude = 0.0;
  this->longitude = 0.0;
}

GPS_DD::GPS_DD(double arg_latitude, double arg_longitude)
{
  this->latitude = arg_latitude;
  this->longitude = arg_longitude;
}

double 
GPS_DD::getLatitude()
{
  return this->latitude;
}
 
double
GPS_DD::getLongitude
()
{
  return this->longitude;
}

// DD distance calculation

/*::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*/
/*::                                                                         :*/
/*::  This routine calculates the distance between two points (given the     :*/
/*::  latitude/longitude of those points). It is being used to calculate     :*/
/*::  the distance between two locations using GeoDataSource(TM) products.   :*/
/*::                                                                         :*/
/*::  Definitions:                                                           :*/
/*::    South latitudes are negative, east longitudes are positive           :*/
/*::                                                                         :*/
/*::  Passed to function:                                                    :*/
/*::    lat1, lon1 = Latitude and Longitude of point 1 (in decimal degrees)  :*/
/*::    lat2, lon2 = Latitude and Longitude of point 2 (in decimal degrees)  :*/
/*::    unit = the unit you desire for results                               :*/
/*::           where: 'M' is statute miles (default)                         :*/
/*::                  'K' is kilometers                                      :*/
/*::                  'N' is nautical miles                                  :*/
/*::  Worldwide cities and other features databases with latitude longitude  :*/
/*::  are available at https://www.geodatasource.com                         :*/
/*::                                                                         :*/
/*::  For enquiries, please contact sales@geodatasource.com                  :*/
/*::                                                                         :*/
/*::  Official Web site: https://www.geodatasource.com                       :*/
/*::                                                                         :*/
/*::           GeoDataSource.com (C) All Rights Reserved 2018                :*/
/*::                                                                         :*/
/*::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*/

#include <math.h>
#define pi 3.14159265358979323846

/*:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*/
/*::  Function prototypes                                           :*/
/*:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*/
double deg2rad(double);
double rad2deg(double);

double GeoDataSource_distance(double lat1, double lon1, double lat2, double lon2, char unit) 
{
  double theta, dist;
  if ((lat1 == lat2) && (lon1 == lon2))
    {
      return 0;
    }
  else
    {
      theta = lon1 - lon2;
      dist = sin(deg2rad(lat1)) * sin(deg2rad(lat2)) + cos(deg2rad(lat1)) * cos(deg2rad(lat2)) * cos(deg2rad(theta));
      dist = acos(dist);
      dist = rad2deg(dist);
      dist = dist * 60 * 1.1515;
      switch(unit)
	{
	case 'M':
	  break;
	case 'K':
	  dist = dist * 1.609344;
	  break;
	case 'N':
	  dist = dist * 0.8684;
	  break;
	}
      return (dist);
    }
}

/*:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*/
/*::  This function converts decimal degrees to radians             :*/
/*:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*/
double deg2rad(double deg)
{
  return (deg * pi / 180);
}

/*:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*/
/*::  This function converts radians to decimal degrees             :*/
/*:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*/
double rad2deg(double rad)
{
  return (rad * 180 / pi);
}

double
GPS_DD::distance
(GPS_DD another)
{
  return GeoDataSource_distance(this->latitude, this->longitude,
				another.getLatitude(), another.getLongitude(), 'M');
}

bool
GPS_DD::operator==
(GPS_DD& aGD)
{
  if ((this->latitude == aGD.latitude) &&
      (this->longitude == aGD.longitude))
    {
      return true;
    }
  else
    {
      return false;
    }
}

Json::Value
GPS_DD::dump2JSON
()
{
  ecs36b_Exception my_exception;
  my_exception.data["typeid"] = string { removeNumberPrefix(typeid(*this).name()) };
  my_exception.data["method"] = "dump2JSON";
  std::string sbuf;
  
  Json::Value result;

  if ((this->latitude > 90.0) || (this->latitude < -90.0))
    {
      sbuf = "latitude value " + to_string(this->latitude) + " is out of range [-90.0, 90.0]";
      my_exception.data["message"] = sbuf;
      my_exception.data["error_code"] = EXC_ERR_OUT_OF_RANGE;
      throw my_exception;
    }

  if ((this->longitude > 180.0) || (this->longitude < -180.0))
    {
      sbuf = "longitude value " + to_string(this->longitude) +
	" is out of range [-180.0, 180.0]";
      my_exception.data["message"] = sbuf;
      my_exception.data["error_code"] = EXC_ERR_OUT_OF_RANGE;
      throw my_exception;
    }

  result["latitude"] = this->latitude;
  result["longitude"] = this->longitude;

#ifdef _ECS36B_DEBUG_
  std::cout << result.toStyledString() << std::endl;
#endif /* _ECS36B_DEBUG_ */
  return result;
}

bool
GPS_DD::JSON2Object
(Json::Value input_json)
{
  ecs36b_Exception my_exception;
  my_exception.data["typeid"] = string { removeNumberPrefix(typeid(*this).name()) };
  my_exception.data["method"] = "JSON2Object";
  std::string sbuf;

  if (input_json.isNull() == true)
    {
      sbuf = "input is a NULL json";
      my_exception.data["message"] = sbuf;
      my_exception.data["error_code"] = EXC_ERR_INPUT_NULL;
      throw my_exception;
    }

  if (input_json.isObject() != true)
    {
      sbuf = "input is not a json object";
      my_exception.data["message"] = sbuf;
      my_exception.data["input"] = input_json;
      my_exception.data["error_code"] = EXC_ERR_INPUT_NOT_OBJECT;
      throw my_exception;
    }

  if ((input_json["latitude"]).isNull() == true)
    {
      sbuf = "missing required attribute \"latitude\"";
      my_exception.data["message"] = sbuf;
      my_exception.data["input"] = input_json;
      my_exception.data["error_code"] = EXC_ERR_MISSING_ATTRIBUTE;
      throw my_exception;
    }

  if ((input_json["longitude"]).isNull() == true)
    {
      sbuf = "missing required attribute \"longitude\"";
      my_exception.data["message"] = sbuf;
      my_exception.data["input"] = input_json;
      my_exception.data["error_code"] = EXC_ERR_MISSING_ATTRIBUTE;
      throw my_exception;
    }

  if ((input_json["latitude"]).isDouble() != true)
    {
      sbuf = "attribute \"latitude\" not double";
      my_exception.data["message"] = sbuf;
      my_exception.data["input"] = input_json;
      my_exception.data["error_code"] = EXC_ERR_DATA_TYPE;
      throw my_exception;
    }

  if ((input_json["longitude"]).isDouble() != true)
    {
      sbuf = "attribute \"longitude\" not double";
      my_exception.data["message"] = sbuf;
      my_exception.data["input"] = input_json;
      my_exception.data["error_code"] = EXC_ERR_DATA_TYPE;
      throw my_exception;
    }

  // we allow GPS_DD to be modified (for mobility)
  this->latitude = (input_json["latitude"]).asDouble();
  this->longitude = (input_json["longitude"]).asDouble();

  return true;
}
