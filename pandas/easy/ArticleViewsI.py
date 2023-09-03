import pandas as pd

def article_views(views: pd.DataFrame) -> pd.DataFrame:
    authors_same_with_viewers = views \
        [views['author_id'] == views['viewer_id']] \
        ['author_id'] \
        .unique()
    
    return pd.DataFrame({'id': sorted(authors_same_with_viewers)})
