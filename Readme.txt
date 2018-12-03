
POST Vars

__VIEWSTATEGENERATOR
__EVENTVALIDATION
__VIEWSTATE

the above can be extracted by GET login page, hidden form fields e.g.

<input type="hidden" name="__VIEWSTATEGENERATOR" id="__VIEWSTATEGENERATOR" value="19FBA8DB" />
<input type="hidden" name="__EVENTVALIDATION" id="__EVENTVALIDATION" value="/wEWBQLg/YSdBwKOspj3AgL/+tKdDgKNqIXqBgKj5J/CBOxHf+LqpQCvc1S/cZeq1T1MuNir" />

txtBadge -   user input
txtPin -   user input
btnClocking   either "Clocking" or "Services"
ServerTime  ?  wierd format, not sure if required?

EntryBox   "1"    unknown?
mode      "0"    unknown?

__LASTFOCUS       - sent but not set
__EVENTTARGET     - sent but not set
__EVENTARGUMENT   - sent but not set

ScriptManager1_HiddenField -

    always set to ";;AjaxControlToolkit, Version=3.5.40412.0, Culture=neutral, PublicKeyToken=28f01b0e84b6d53e:en-GB:065e08c0-e2d1-42ff-9483-e5c14441b311:475a4ef5:effe2a26:3ac3e789"
