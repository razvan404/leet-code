import pandas as pd

def find_customers(customers: pd.DataFrame, orders: pd.DataFrame) -> pd.DataFrame:
    unique_order_customer_ids = pd.unique(orders['customerId'])
    return customers \
        [~customers['id'].isin(unique_order_customer_ids)] \
        [['name']] \
        .rename(columns={'name': 'Customers'})
