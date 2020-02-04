#pragma once
struct MobEffectInstance {
    int getId() const;
    int getAmplifier() const;
    std::string getDisplayName() const;
    int getDuration() const;
    int getLingerDuration() const;
    int getSplashDuration() const;
    int getDescriptionId() const;
};