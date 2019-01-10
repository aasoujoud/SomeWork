package com.example.ali.myapplication;

import android.content.Intent;
import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.view.View;
import android.widget.AdapterView;
import android.widget.ArrayAdapter;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Spinner;
import android.widget.TextView;
import android.widget.Toast;

public class PersonalInfoActivity extends AppCompatActivity {
    private String stateText;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_personal_info);

        final validatorAndVolunteer Volunteer = new validatorAndVolunteer();


        TextView preAssignTV= findViewById(R.id.assignedAreaTextView);
        TextView preVolunTV = findViewById(R.id.previousVolunteerExpTextView);
        TextView learnAboutTV = findViewById(R.id.learnAboutTextView);
        final EditText preVolunET = findViewById(R.id.previousVolunteerExpEditText);
        final EditText learnAboutET = findViewById(R.id.learnAboutEditText);

        final EditText preAssignET= findViewById(R.id.assignedAreaEditText);



        final EditText suffix = findViewById(R.id.suffixEditText);    // ( Full Name )
        final EditText firstName = findViewById(R.id.firstNameEditText);    // ( Full Name )
        final EditText lastName = findViewById(R.id.lastNameEditText);
        final EditText middleInitial = findViewById(R.id.middleInitialEditText);

        final EditText streetAddress = findViewById(R.id.addressEditText);    // (Address info)
        final EditText city = findViewById(R.id.CityEditText);
        final EditText zipCode = findViewById(R.id.zipCodeEditText);

        final EditText cellPhone = findViewById(R.id.cellPHoneEditText);
        final EditText homePhone = findViewById(R.id.homePhoneEditText);

        final EditText birthDate = findViewById(R.id.birthDateEditText);
        final EditText birthLocation = findViewById(R.id.birthLocationEditText);
        final EditText committee = findViewById(R.id.committeInterestEditText);
        final EditText assignWith = findViewById(R.id.assignWithEditText);
        





        Bundle extras = getIntent().getExtras();
        final int memberStats = extras.getInt("memberStatus");
        if(memberStats== 1){
            preAssignET.setVisibility(View.GONE);
            preAssignTV.setVisibility(View.GONE);
        }
        else if(memberStats ==2){
            preVolunTV.setVisibility(View.GONE);
            preVolunET.setVisibility(View.GONE);
            learnAboutTV.setVisibility(View.GONE);
            learnAboutET.setVisibility(View.GONE);
        }



        Button nextButton = findViewById(R.id.nextBtn);

        ArrayAdapter<CharSequence> statesAdapter;
        statesAdapter = ArrayAdapter.createFromResource(this,R.array.states,android.R.layout.simple_spinner_item);
        statesAdapter.setDropDownViewResource(android.R.layout.simple_spinner_dropdown_item);
        final Spinner stateSpinner = findViewById(R.id.stateSpinner);
        stateSpinner.setAdapter(statesAdapter);
        stateSpinner.setOnItemSelectedListener(new AdapterView.OnItemSelectedListener() {
            @Override
            public void onItemSelected(AdapterView<?> parent, View view, int position, long id) {
                stateText = parent.getItemAtPosition(position).toString();
                if(!(stateText.equals("State"))) {
                    TextView test = (TextView)findViewById(R.id.tabTextView);
                    if((stateText.equals("FL"))) {
                        Toast.makeText(PersonalInfoActivity.this, "dwd", Toast.LENGTH_SHORT).show();
                    }
                }
            }
            @Override
            public void onNothingSelected(AdapterView<?> parent) {
                //LEave empty since it will always be selected!
            }
        });

        ArrayAdapter<CharSequence> tshirtSizeAdapter;
        tshirtSizeAdapter = ArrayAdapter.createFromResource(this,R.array.tshirtSizes,android.R.layout.simple_spinner_item);
        tshirtSizeAdapter.setDropDownViewResource(android.R.layout.simple_spinner_dropdown_item);
        Spinner tshirtSizeSpinner= findViewById(R.id.tshirtSizeSpinner);
        tshirtSizeSpinner.setAdapter(tshirtSizeAdapter);
        tshirtSizeSpinner.setOnItemSelectedListener(new AdapterView.OnItemSelectedListener() {
            @Override
            public void onItemSelected(AdapterView<?> parent, View view, int position, long id) {
                String text = parent.getItemAtPosition(position).toString();
                if(!(text.equals("Size"))) {

                }
            }
            @Override
            public void onNothingSelected(AdapterView<?> parent) {
                // Leave empty since a size will always be selected!
            }
        });

        nextButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
               /* boolean isSuffixValid = Volunteer.validateName((suffix.getText().toString()), suffix);
                boolean isFirstNameValid = Volunteer.validateName((firstName.getText().toString()), firstName);
                boolean isLastNameValid = Volunteer.validateName((lastName.getText().toString()), lastName);
                boolean isStreetAddressValid = Volunteer.validateAddress((streetAddress.getText().toString()),streetAddress);
                boolean isZipCodeValid = Volunteer.validateAddress((zipCode.getText().toString()),zipCode);
                boolean isCityValid = Volunteer.validateAddress((city.getText().toString()),city);
                //boolean isEmailValid = Volunteer.validateEmail((emailAddress.getText().toString().trim()), emailAddress);
                boolean isCellPhoneValid = Volunteer.validatePhoneNumber((cellPhone.getText().toString()), cellPhone);
                boolean isBirthDateValid = Volunteer.validateDate((birthDate.getText().toString()),birthDate);
                boolean isBirthLocationValid = Volunteer.validateString(birthLocation.getText().toString(),birthLocation);
                boolean isMemberOrRenewalValid = false;


                if(memberStats == 1){
                    boolean isLearnAboutValid = Volunteer.validateString((learnAboutET.getText().toString()),learnAboutET);
                    boolean isPrevVolunteerExpValid = Volunteer.validateString((preVolunET.getText().toString()),preVolunET);
                    if(isLearnAboutValid && isPrevVolunteerExpValid){
                        Volunteer.setPreviousExp(preVolunET.getText().toString());
                        Volunteer.setLearnAbout(learnAboutET.getText().toString());
                        isMemberOrRenewalValid = true;
                    }
                }else if(memberStats == 2){
                    boolean isPreAssignWithValid = Volunteer.validateString((preAssignET.getText().toString()),preAssignET);
                    if(isPreAssignWithValid){
                        Volunteer.setPreviousAssign(preAssignET.getText().toString());
                        isMemberOrRenewalValid = true;
                    }
                }

                if(!middleInitial.getText().toString().isEmpty()){
                    boolean isMiddleInitialValid = Volunteer.validateName((middleInitial.getText().toString()), middleInitial);
                    if (isMiddleInitialValid){
                        Volunteer.setMiddleInitial(middleInitial.getText().toString());
                    }
                }

                if(!assignWith.getText().toString().isEmpty()){
                    boolean isAssignWith = Volunteer.validateString((assignWith.getText().toString()), assignWith);
                    if (isAssignWith){
                        Volunteer.setAssignWith(assignWith.getText().toString());
                    }
                }

                if(!committee.getText().toString().isEmpty()){
                    boolean isCommitteeValid = Volunteer.validateString((committee.getText().toString()), committee);
                    if (isCommitteeValid){
                        Volunteer.setCommittee(committee.getText().toString());
                    }
                }

                if(!homePhone.getText().toString().isEmpty()){ // if it is not empty since it is not a required field, we will try validate it!
                    boolean isHomePhoneValid = Volunteer.validatePhoneNumber((homePhone.getText().toString()),homePhone);
                    if (isHomePhoneValid){
                        Volunteer.setHome(homePhone.getText().toString());
                    }
                }*/





               // if(isSuffixValid && isFirstNameValid && isLastNameValid && isStreetAddressValid && isBirthLocationValid && isZipCodeValid && isCityValid  && isCellPhoneValid && isBirthDateValid &&isMemberOrRenewalValid  ) {  // If all fields are true, it will continue.//

                    //Volunteer.sendVolunteerInfo(suffix.getText().toString(),firstName.getText().toString(),lastName.getText().toString(),middleInitial.getText().toString(),
                     //       streetAddress.getText().toString(),city.getText().toString(),zipCode.getText().toString(), "MI","small",cellPhone.getText().toString());

                    Intent startIntent = new Intent(getApplicationContext(), EmergencyContactActivity.class);
                    startIntent.putExtra("memberStatus", memberStats);
                    startIntent.putExtra("Volunteer" , Volunteer);
                    startActivity(startIntent);

                    overridePendingTransition(R.anim.slide_in_right, R.anim.slide_out_left);
               // }else {
                 //   Toast.makeText(PersonalInfoActivity.this, "Please review above fields and try again!", Toast.LENGTH_SHORT).show();
                //}

            }
        });

    }
}

