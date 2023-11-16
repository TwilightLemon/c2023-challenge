//
// Created by cz241 on 11/6/2023.
//

#include "BoardDrawer.h"
#include <iostream>
#include <thread>

int TotalSteps=0;
int BoardDrawer::GetSteps() {
    return TotalSteps;
}
void BoardDrawer::ResetStep(){
    TotalSteps=0;
}
void BoardDrawer::Round(int sleepTime){
    //绘制当前玩家：
    string current= "CurrentPlayer: ";
    current.append(CurrentPlayer==PieceStatus::Black?"Black":"White");
    DrawText(current.c_str(),20,Board_Size+40,20,BLACK);
    Point p;
    if(Players[0]->PlayerColor==CurrentPlayer) {
        p = Players[0]->NextStep();
    }else{
        p = Players[1]->NextStep();
    }
    if(p.x==-1&&p.y==-1)return;
    cout<<"POINT AT: "<<p.x<<" "<<p.y<<endl;
    MapData[p.x][p.y]=CurrentPlayer;
    ExchangePlayer();
    TotalSteps++;
    if(sleepTime!=0)this_thread::sleep_for(chrono::milliseconds(sleepTime));
}

void BoardDrawer::ExchangePlayer() {
    CurrentPlayer = CurrentPlayer == PieceStatus::Black ? PieceStatus::White : PieceStatus::Black;
}

void BoardDrawer::DrawBackground() {
    for(int i=0;i<15;i++){
        DrawLineEx({Margin,Margin+i*GridSize},{Board_Size+Margin,Margin+i*GridSize},LineThick,BLACK);
        DrawLineEx({Margin+i*GridSize,Margin},{Margin+i*GridSize,Board_Size+Margin},LineThick,BLACK);
    }
}

void BoardDrawer::DrawPieces(){
    for(int x=0;x<15;x++){
        for(int y=0;y<15;y++){
            if(MapData[x][y] == PieceStatus::Black){
                DrawCircle(20+x*GridSize,20+y*GridSize,PieceSize,BLACK);
            }
            if(MapData[x][y]==PieceStatus::White){
                DrawCircle(20+x*GridSize,20+y*GridSize,PieceSize,WHITE);
            }
        }
    }
}

PieceStatus  BoardDrawer::IfWined(bool& drew){
    Color LineColor=BLUE;
    Vector2 p_start,p_end;
    PieceStatus IfWin=PieceStatus::None;
    int pieceCount=0;
    //判断是否胜利，一个没有效率的方法：
    for(int x=0;x<15;x++) {
        for (int y = 0; y < 15; y++) {
            if (MapData[x][y] == PieceStatus::None)continue;
            pieceCount++;
            //判断横向：
            if (x <= 10 && MapData[x][y] == MapData[x + 1][y] && MapData[x][y] == MapData[x + 2][y] &&
                MapData[x][y] == MapData[x + 3][y] && MapData[x][y] == MapData[x + 4][y]) {
                p_start={Margin + x * GridSize, Margin + y * GridSize};
                p_end={Margin + (x + 4) * GridSize, Margin + y * GridSize};
                IfWin=MapData[x][y];
            }
            //判断纵向：
            if (y <= 10 && MapData[x][y] == MapData[x][y + 1] && MapData[x][y] == MapData[x][y + 2] &&
                MapData[x][y] == MapData[x][y + 3] && MapData[x][y] == MapData[x][y + 4]) {
                p_start={Margin + x * GridSize, Margin + y * GridSize};
                p_end={Margin + x * GridSize, Margin + (y + 4) * GridSize};
                IfWin=MapData[x][y];
            }
            //判断左上到右下:
            if (x <= 10 && y <= 10 && MapData[x][y] == MapData[x + 1][y + 1] &&
                MapData[x][y] == MapData[x + 2][y + 2] && MapData[x][y] == MapData[x + 3][y + 3] &&
                MapData[x][y] == MapData[x + 4][y + 4]) {
                p_start={Margin + x * GridSize, Margin + y * GridSize};
                p_end={Margin + (x + 4) * GridSize, Margin + (y + 4) * GridSize};
                IfWin=MapData[x][y];
            }
            //判断右上到左下:
            if (x >= 4 && y <= 10 && MapData[x][y] == MapData[x - 1][y + 1] && MapData[x][y] == MapData[x - 2][y + 2] &&
                MapData[x][y] == MapData[x - 3][y + 3] && MapData[x][y] == MapData[x - 4][y + 4]) {
                p_start={Margin + x * GridSize, Margin + y * GridSize};
                p_end={Margin + (x - 4) * GridSize, Margin + (y + 4) * GridSize};
                IfWin=MapData[x][y];
            }
        }
    }
    if(IfWin!=PieceStatus::None){
        DrawLineEx(p_start, p_end, LineThick+2, LineColor);
        return IfWin;
    }else{
        if(pieceCount==225){
            drew=true;
        }
    }
    return PieceStatus::None;
}