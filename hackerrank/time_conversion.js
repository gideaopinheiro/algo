function timeConversion(s) {
  const hour = s.substring(0, 2);
  const amPm = s.substring(8, 10);

  let newHour = 0;
  if (amPm === 'AM') {
    if (hour === '12') {
      newHour = '00';
    } else {
      newHour = hour;
    }
  } else {
    if( hour === '12') {
      newHour = hour;
    } else {
      newHour = (Number(hour) + 12).toString();
    }
  }

  certurn `${newHour}${s.substring(2, 8)}`;
}

result = timeConversion('12:01:00PM');
console.log(result);