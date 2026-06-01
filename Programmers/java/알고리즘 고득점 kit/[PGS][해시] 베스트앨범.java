import java.util.*;

class Solution {
    static class Song {
        int id;
        int play;
        
        public Song(int id, int play) {
            this.id = id;
            this.play = play;
        }
    }
    
    public int[] solution(String[] genres, int[] plays) { 
        int[] answer = {};
        
        Map<String, List<Song>> genreSong = new HashMap<>();
        Map<String, Integer> genreTotal = new HashMap<>();
        
        // 1. 데이터 저장
        for(int i = 0; i < genres.length; i++){
            // 1-1 장르별 전체 재생 횟수 저장
            genreTotal.put(genres[i], genreTotal.getOrDefault(genres[i], 0) + plays[i]);
            
            // 1-2 장르 > 곡별 재생 횟수 저장 
            if(!genreSong.containsKey(genres[i])) { 
                genreSong.put(genres[i], new ArrayList<>());    
            } 
            genreSong.get(genres[i]).add(new Song(i, plays[i]));
            /*
            genreSong.computeIfAbsent(genre[i], g -> new ArrayList<>()).add(new Song(i, plays[i]));
            */
        }
        
        // 2. 장르별 전체 곡 재생 수 정렬
        List<String> orderedGenres = new ArrayList<>(genreTotal.keySet());
        orderedGenres.sort((o1, o2) -> genreTotal.get(o2) - genreTotal.get(o1));
        
        // 3. 장르별로 최대 두 곡씩
        List<Integer> album = new ArrayList<>();
        for(String genre : orderedGenres) {
            // 3-1 Song 리스트 가져와서 정렬
            List<Song> list = genreSong.get(genre);
            list.sort((o1, o2) -> {
                if(o2.play == o1.play) {
                    return o1.id - o2.id;       // 고유번호 오름차순
                }
                return o2.play - o1.play;       // 재생 수 내림차순
            });
            
            // 3-2 album에 저장
            album.add(list.get(0).id);
            if(list.size() > 1) album.add(list.get(1).id);
        }
        
        answer = album.stream().mapToInt(i -> i).toArray();
        
        return answer;
        
        
        /*
        
        int[] answer = {};
        List<Integer> album = new ArrayList<>();
        
       // 장르 : 곡 수
        Map<String, Integer> mGenrePlayCount = new HashMap<>();
        for(int i = 0; i < genres.length; i++) {
            mGenrePlayCount.put(genres[i], mGenrePlayCount.getOrDefault(genres[i], 0) + plays[i]);
        }
        // System.out.println(mGenrePlayCount);
        
        // 리스트로 만들어서 정렬
        List<Map.Entry<String, Integer>> genreOrderedList = new ArrayList<>(mGenrePlayCount.entrySet());
        Collections.sort(genreOrderedList, new Comparator<Map.Entry<String, Integer>>(){
            @Override
            public int compare(Map.Entry<String, Integer> o1, Map.Entry<String, Integer> o2){
                return o2.getValue() - o1.getValue();
            }
        });
        // System.out.println(genreOrderedList);
        
        
        // 장르별로 곡의 고유번호와 재생 수 저장
        // classic : {
        //     1 : 500,
        //     3 : 150,
        // },
        // pop : {
        //     0 : 600,
        //     ...
        // }
        Map<String, Map<Integer, Integer>> mGenreSongCount = new HashMap<>();
        for(int i = 0; i < genres.length; i++) {
            if(!mGenreSongCount.containsKey(genres[i])) {
                Map<Integer, Integer> data = new HashMap<>();
                data.put(i, plays[i]);
                mGenreSongCount.put(genres[i], data);
            }else {
                mGenreSongCount.get(genres[i]).put(i, plays[i]);
            }
        }
        // System.out.println(mGenreSongCount);
        
        
        // 장르별 재생 곡 수 기준으로 정렬
        for(Map.Entry<String, Integer> order : genreOrderedList) {
            String genre = order.getKey();
            List<Map.Entry<Integer, Integer>> list = new ArrayList<>(mGenreSongCount.get(genre).entrySet());
            // 정렬
            Collections.sort(list, new Comparator<Map.Entry<Integer, Integer>>() {
                @Override
                public int compare(Map.Entry<Integer, Integer> o1, Map.Entry<Integer, Integer> o2){
                    return o2.getValue() - o1.getValue();
                }
            });
            // System.out.println(list);
            
            // 앨범에 저장
            album.add(list.get(0).getKey());
            if(list.size() > 1) album.add(list.get(1).getKey());
        }
        
        // System.out.println(album);
         
        answer = album.stream().mapToInt(i -> i).toArray();
        
        return answer;
        
        */
        
        
        
        
    }
}