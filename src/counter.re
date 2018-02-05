type action = 
  | Increase
  | Decrease;

type state = {
  count: int
};

let component = ReasonReact.reducerComponent("Counter");

let make = (_children) => {
  ...component,
  initialState: () => { count: 0 },
  reducer: (action, state) => 
    switch(action) {
    | Increase => ReasonReact.Update({...state, count: state.count + 1})
    | Decrease => ReasonReact.Update({...state, count: state.count - 1})
    },
  render: (self) => {
    <div>
      <button onClick={_event => self.send(Increase)}> {ReasonReact.stringToElement("+")} </button>
      <div> {ReasonReact.stringToElement(string_of_int(self.state.count))} </div>
      <button onClick={ _event => self.send(Decrease) }> {ReasonReact.stringToElement("-")} </button>
    </div>
  }
};

