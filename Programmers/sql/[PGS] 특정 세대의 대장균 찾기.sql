-- 3세대 대장균 아이디 오름차순 정렬

# SELECT id
#   FROM ecoli_data
#  WHERE parent_id IN (SELECT id
#                        FROM ecoli_data
#                       WHERE parent_id IN (SELECT id
#                                             FROM ecoli_data
#                                            WHERE parent_id IS NULL)
#                     )                
#  ORDER BY id
 
-- SELF JOIN 사용한 풀이
SELECT child.id
  FROM ecoli_data child
       JOIN ecoli_data parent 
       ON   child.parent_id = parent.id
       JOIN ecoli_data grand
       ON   parent.parent_id = grand.id
        AND grand.parent_id IS NULL
 ORDER BY child.id