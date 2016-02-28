package com.ua.alt;

import javafx.application.Application;
import javafx.scene.Group;
import javafx.scene.Scene;
import javafx.scene.canvas.Canvas;
import javafx.scene.canvas.GraphicsContext;
import javafx.scene.paint.Color;
import javafx.scene.shape.ArcType;
import javafx.stage.Stage;

/**
 * Created by BOSS on 27.02.16.
 */
public class GraphImp implements Graph{
    @Override
    public void createGraph() {
        Canvas canvas = new Canvas(312, 486);
    }

    @Override
    public int constructGraph(int a, int x, int y) {
        return 0;
    }

    @Override
    public void clearGraphic() {

    }

    @Override
    public void scaleGraphic() {

    }
}
