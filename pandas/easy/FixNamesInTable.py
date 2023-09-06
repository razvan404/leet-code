import pandas as pd

def fix_names(users: pd.DataFrame) -> pd.DataFrame:
    users['name'] = users['name'].apply(lambda name: name.capitalize())
    return users.sort_values(by='user_id')
