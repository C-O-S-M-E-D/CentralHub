using UnityEngine;
using System.Collections;
using UnityEngine.UI;

public class PatientProfileDataScript : MonoBehaviour {

	public GameObject full_name_textbox;
	public PatientDatabaseManager databaseManager;

	public void SetInfo(string patient_name) {
		databaseManager.GetPatientData(2);
		this.full_name_textbox.GetComponent<Text>().text = ;
	}

}
