$students = import-csv ".\people_student.csv"
ForEach ($student in $students){
$Name = $($student.Name)
$Surname = $($student.Surname)
$Class = $($student.Class)
Write-host $Name $Surname $Class
New-Item -Path "./People/Student/$Class/$Name.$Surname/" -ItemType Directory -Force
}