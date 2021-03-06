/*
 * DISTRHO ProM Plugin
 * Copyright (C) 2014 Filipe Coelho <falktx@falktx.com>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU Lesser General Public License for more details.
 *
 * For a full copy of the license see the LICENSE file.
 */

#ifndef DISTRHO_PLUGIN_3BANDEQ_HPP_INCLUDED
#define DISTRHO_PLUGIN_3BANDEQ_HPP_INCLUDED

#include "DistrhoPlugin.hpp"

#include "extra/d_mutex.hpp"

class projectM;
class DistrhoUIProM;

START_NAMESPACE_DISTRHO

// -----------------------------------------------------------------------

class DistrhoPluginProM : public Plugin
{
public:
    DistrhoPluginProM();
    ~DistrhoPluginProM() override;

protected:
    // -------------------------------------------------------------------
    // Information

    const char* d_getLabel() const noexcept override
    {
        return "ProM";
    }

    const char* d_getMaker() const noexcept override
    {
        return "DISTRHO";
    }

    const char* d_getLicense() const noexcept override
    {
        return "LGPL";
    }

    uint32_t d_getVersion() const noexcept override
    {
        return 0x1000;
    }

    int64_t d_getUniqueId() const noexcept override
    {
        return d_cconst('D', 'P', 'r', 'M');
    }

    // -------------------------------------------------------------------
    // Init

    void d_initParameter(uint32_t, Parameter&) override;

    // -------------------------------------------------------------------
    // Internal data

    float d_getParameterValue(uint32_t) const override;
    void  d_setParameterValue(uint32_t, float) override;

    // -------------------------------------------------------------------
    // Process

    void d_run(const float** inputs, float** outputs, uint32_t frames) override;

    // -------------------------------------------------------------------

private:
    Mutex fMutex;
    projectM* fPM;
    friend class DistrhoUIProM;

    DISTRHO_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(DistrhoPluginProM)
};

// -----------------------------------------------------------------------

END_NAMESPACE_DISTRHO

#endif  // DISTRHO_PLUGIN_3BANDEQ_HPP_INCLUDED
