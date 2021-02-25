# https://programmers.co.kr/learn/courses/30/lessons/17683

def solution(m, musicinfos):
    notes = ["C#", "D#", "F#", "G#", "A#",
             "C", "D", "E", "F", "G", "A", "B"]

    answer = []

    # 음악 플레이 시간을 반환합니다.
    def play_time(start, end):
        start_hour, start_min = map(int, start.split(':'))
        end_hour, end_min = map(int, end.split(':'))
        return (end_hour - start_hour) * 60 + (end_min - start_min)

    # 음을 코드로 변환합니다.
    def music_to_code(music):
        for i, note in enumerate(notes):
            music = music.replace(note, format(i, 'x'))
        return music

    m_code = music_to_code(m)
    for music in musicinfos:
        start, end, title, melody = music.split(',')
        time = play_time(start, end)
        melody_code = music_to_code(melody)
        # 음악 길이가 재생 시간보다 짧을 때,
        # 음악 길이를 재생 시간만큼 연장한다.
        if len(melody_code) < time:
            melody_code = melody_code * (time // len(melody_code) + 1)
        melody_code = melody_code[:time]

        # 조건이 일치하는 음악이 여러 개일 때에는
        # 라디오에서 재생된 시간이 제일 긴 음악 제목을
        # 반환한다.
        if m_code in melody_code:
            answer.append((-time, title))

    answer.sort()
    return answer[0][1] if answer else "(None)"


print(solution("ABCDEFG",
               ["12:00,12:14,HELLO,CDEFGAB", "13:00,13:05,WORLD,ABCDEF"]))
