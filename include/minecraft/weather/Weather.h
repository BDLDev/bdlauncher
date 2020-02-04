#pragma once

class Dimension;
class LevelData;

class Weather{
public:
Weather(Dimension&);
~Weather();
void serverTick();
void setFogLevel(float);
void setRainLevel(float);
void setSkyFlashTime(int);
void setLightningLevel(float);
void stop();
void tick();
float getFogLevel() const;
bool isLightning() const;
float getRainLevel(float) const;
int getSkyFlashTime() const;
float getLightningLevel(float) const;
bool isRaining() const;
void _notifyWeatherChangedEvent(LevelData const&) const;
};
