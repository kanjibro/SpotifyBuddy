#ifndef WEB_FETCH_H
#define WEB_FETCH_H

#include <HTTPClient.h>
#include <ArduinoJson.h>

String getSpotifyToken() {
  HTTPClient http;
  http.begin("https://accounts.spotify.com/api/token");
  http.addHeader("Content-Type", "application/x-www-form-urlencoded");
  String body = "grant_type=refresh_token&refresh_token=" + String(SPOTIFY_REFRESH_TOKEN) + 
                "&client_id=" + String(SPOTIFY_CLIENT_ID) + "&client_secret=" + String(SPOTIFY_CLIENT_SECRET);
  int httpCode = http.POST(body);
  
  String token = "";
  if (httpCode == 200) {
    DynamicJsonDocument doc(1024);
    deserializeJson(doc, http.getString());
    token = doc["access_token"].as<String>();
  }
  http.end();
  return token;
}

String getCurrentTrack(String token) {
  HTTPClient http;
  http.begin("https://api.spotify.com/v1/me/player/currently-playing");
  http.addHeader("Authorization", "Bearer " + token);
  int httpCode = http.GET();
  
  String track = "Unknown";
  if (httpCode == 200) {
    DynamicJsonDocument doc(2048);
    deserializeJson(doc, http.getString());
    track = doc["item"]["name"].as<String>();
  }
  http.end();
  return track;
}

void controlSpotify(String action) {
  HTTPClient http;
  String endpoint = "https://api.spotify.com/v1/me/player/" + action;
  http.begin(endpoint);
  http.addHeader("Authorization", "Bearer " + access_token);
  http.POST("");
  http.end();
}

#endif
