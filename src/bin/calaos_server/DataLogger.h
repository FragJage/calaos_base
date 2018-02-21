/******************************************************************************
 **  Copyright (c) 2006-2017, Calaos. All Rights Reserved.
 **
 **  This file is part of Calaos.
 **
 **  Calaos is free software; you can redistribute it and/or modify
 **  it under the terms of the GNU General Public License as published by
 **  the Free Software Foundation; either version 3 of the License, or
 **  (at your option) any later version.
 **
 **  Calaos is distributed in the hope that it will be useful,
 **  but WITHOUT ANY WARRANTY; without even the implied warranty of
 **  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 **  GNU General Public License for more details.
 **
 **  You should have received a copy of the GNU General Public License
 **  along with Foobar; if not, write to the Free Software
 **  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 **
 ******************************************************************************/
#ifndef __DATA_LOGGER_H
#define __DATA_LOGGER_H

#include <IOBase.h>
#include "LightTSDB.h"

namespace Calaos
{

class DataLogger
{
private:
    DataLogger();
    LightTSDB::LightTSDB m_LightTSDB;

public:
    static DataLogger &Instance()
    {
        static DataLogger inst;
        return inst;
    }
    ~DataLogger();

    void log(IOBase *io);
    bool GetSensorList(std::list<std::string>& sensorList);
    bool GetSensorInfo(const std::string& sensor, LightTSDB::SensorInfo& sensorInfo);
    bool ReadValues(const std::string& sensor, time_t hour, std::list<LightTSDB::DataValue>& values);
    bool ReadValues(const std::string& sensor, time_t hourBegin, time_t hourEnd, std::list<LightTSDB::DataValue>& values);
    bool ReadLastValue(const std::string& sensor, LightTSDB::DataValue& value);
    bool ResampleValues(const std::string& sensor, time_t timeBegin, time_t timeEnd, std::list<LightTSDB::DataValue>& values, int interval, int* nbValues);
};

}
#endif /* __DATA_LOGGER_H */
