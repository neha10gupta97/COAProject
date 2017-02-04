package com.example.nehalnm.textmsg;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.app.Activity;
import android.telephony.SmsManager;
import android.view.Menu;
import android.widget.Toast;


public class MainActivity extends AppCompatActivity {

    Button sendBtn;

    EditText txtphoneNo;
    EditText txtMessage;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        sendBtn =(Button) findViewById(R.id.button);
        txtphoneNo =(EditText) findViewById(R.id.phn);
        txtMessage =(EditText) findViewById(R.id.msg);




        sendBtn.setOnClickListener(new View.OnClickListener(){
           public void onClick (View view){
               sendSMS();
           }
        });
    }



    protected void sendSMS(){
        Log.i("Send SMS","");
        String phnno =txtphoneNo.getText().toString();
        String message =txtMessage.getText().toString();

        try{
            SmsManager smsManager =SmsManager.getDefault();
            smsManager.sendTextMessage(phnno ,null,message,null,null);
            Toast.makeText(getApplicationContext(),"SMS sent...yeyy!!",Toast.LENGTH_LONG).show();
        }
        catch (Exception e){
            Toast.makeText(getApplicationContext(),"SMS failed :/",Toast.LENGTH_LONG).show();
        }
    }
}
