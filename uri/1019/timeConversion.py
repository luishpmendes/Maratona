seconds = int(raw_input())
minutes = seconds / 60
seconds = seconds - 60 * minutes
hours = minutes / 60
minutes = minutes - 60 * hours
print(str(hours) + ':' + str(minutes) + ':' + str(seconds))
