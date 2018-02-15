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
#include <DataLogger.h>
#include <IOBase.h>

using namespace Calaos;
using namespace LightTSDB;

#define CALAOS_DATALOGGER_FOLDER "datalogger"

DataLogger::DataLogger()
{
    string dbFolder = getCacheFile(CALAOS_DATALOGGER_FOLDER);
    mkdir(dbFolder.c_str(), S_IRWXU);
    m_LightTSDB.SetFolder(dbFolder);
}

DataLogger::~DataLogger()
{
}

void DataLogger::log(IOBase *io)
{
    if (io->get_param("logged") == "true")
    {
        tzset(); //Force reload of timezone data
        m_LightTSDB.WriteValue(io->get_param("id"), io->get_value_double());
    }
}

bool DataLogger::ReadValues(const string& sensor, time_t hour, list<DataValue>& values)
{
    return m_LightTSDB.ReadValues(sensor, hour, values);
}

bool DataLogger::ReadValues(const string& sensor, time_t hourBegin, time_t hourEnd, list<DataValue>& values)
{
    return m_LightTSDB.ReadValues(sensor, hourBegin, hourEnd, values);
}

bool DataLogger::ReadLastValue(const string& sensor, DataValue& value)
{
    return m_LightTSDB.ReadLastValue(sensor, value);
}

bool DataLogger::ResampleValues(const string& sensor, time_t timeBegin, time_t timeEnd, list<DataValue>& values, int interval)
{
    return m_LightTSDB.ResampleValues(sensor, timeBegin, timeEnd, values, interval);
}

