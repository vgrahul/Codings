/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package sound;

/**
 *
 * @author Rahul V
 */
public class Sound {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
 double[] sounddata = StdAudio.read("ee20.wav");
    StdAudio.play(sounddata)
           ;
         }
    
}
