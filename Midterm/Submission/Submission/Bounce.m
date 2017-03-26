function varargout = Bounce(varargin)
% BOUNCE MATLAB code for Bounce.fig
%      BOUNCE, by itself, creates a new BOUNCE or raises the existing
%      singleton*.
%
%      H = BOUNCE returns the handle to a new BOUNCE or the handle to
%      the existing singleton*.
%
%      BOUNCE('CALLBACK',hObject,eventData,handles,...) calls the local
%      function named CALLBACK in BOUNCE.M with the given input arguments.
%
%      BOUNCE('Property','Value',...) creates a new BOUNCE or raises the
%      existing singleton*.  Starting from the left, property value pairs are
%      applied to the GUI before Bounce_OpeningFcn gets called.  An
%      unrecognized property name or invalid value makes property application
%      stop.  All inputs are passed to Bounce_OpeningFcn via varargin.
%
%      *See GUI Options on GUIDE's Tools menu.  Choose "GUI allows only one
%      instance to run (singleton)".
%
% See also: GUIDE, GUIDATA, GUIHANDLES

% Edit the above text to modify the response to help Bounce

% Last Modified by GUIDE v2.5 21-Mar-2017 22:27:30

% Begin initialization code - DO NOT EDIT
gui_Singleton = 1;
gui_State = struct('gui_Name',       mfilename, ...
                   'gui_Singleton',  gui_Singleton, ...
                   'gui_OpeningFcn', @Bounce_OpeningFcn, ...
                   'gui_OutputFcn',  @Bounce_OutputFcn, ...
                   'gui_LayoutFcn',  [] , ...
                   'gui_Callback',   []);
if nargin && ischar(varargin{1})
    gui_State.gui_Callback = str2func(varargin{1});
end

if nargout
    [varargout{1:nargout}] = gui_mainfcn(gui_State, varargin{:});
else
    gui_mainfcn(gui_State, varargin{:});
end
% End initialization code - DO NOT EDIT


% --- Executes just before Bounce is made visible.
function Bounce_OpeningFcn(hObject, eventdata, handles, varargin)
% This function has no output args, see OutputFcn.
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
% varargin   command line arguments to Bounce (see VARARGIN)

% Choose default command line output for Bounce
handles.output = hObject;
handles.x0 = 1;
handles.y0 = 1;
handles.vx0 = 100;
handles.vy0 = 100;
handles.mass = 1;
handles.radius = 0.5;
handles.e = 0.85;
handles.smoothBool = 1;
handles.n = 10;
handles.time = [];
handles.xDat = [];
handles.yDat = [];
handles.PLOTOPTION = 1;
% Update handles structure
guidata(hObject, handles);

% UIWAIT makes Bounce wait for user response (see UIRESUME)
% uiwait(handles.figure1);


% --- Outputs from this function are returned to the command line.
function varargout = Bounce_OutputFcn(hObject, eventdata, handles) 
% varargout  cell array for returning output args (see VARARGOUT);
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Get default command line output from handles structure
varargout{1} = handles.output;



function x0_Callback(hObject, eventdata, handles)
% hObject    handle to x0 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of x0 as text
%        str2double(get(hObject,'String')) returns contents of x0 as a double
handles.x0 = str2double(get(hObject,'String'));
guidata(hObject,handles);

% --- Executes during object creation, after setting all properties.
function x0_CreateFcn(hObject, eventdata, handles)
% hObject    handle to x0 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end



function y0_Callback(hObject, eventdata, handles)
% hObject    handle to y0 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of y0 as text
%        str2double(get(hObject,'String')) returns contents of y0 as a double

handles.y0 = str2double(get(hObject,'String'));
guidata(hObject,handles);

% --- Executes during object creation, after setting all properties.
function y0_CreateFcn(hObject, eventdata, handles)
% hObject    handle to y0 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end



function vx0_Callback(hObject, eventdata, handles)
% hObject    handle to vx0 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of vx0 as text
%        str2double(get(hObject,'String')) returns contents of vx0 as a double
handles.vx0 = str2double(get(hObject,'String'));
guidata(hObject,handles);

% --- Executes during object creation, after setting all properties.
function vx0_CreateFcn(hObject, eventdata, handles)
% hObject    handle to vx0 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end



function vy0_Callback(hObject, eventdata, handles)
% hObject    handle to vy0 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of vy0 as text
%        str2double(get(hObject,'String')) returns contents of vy0 as a double
handles.vy0 = str2double(get(hObject,'String'));
guidata(hObject,handles);

% --- Executes during object creation, after setting all properties.
function vy0_CreateFcn(hObject, eventdata, handles)
% hObject    handle to vy0 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end



function mass0_Callback(hObject, eventdata, handles)
% hObject    handle to mass0 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of mass0 as text
%        str2double(get(hObject,'String')) returns contents of mass0 as a double
handles.mass = str2double(get(hObject,'String'));
guidata(hObject,handles);

% --- Executes during object creation, after setting all properties.
function mass0_CreateFcn(hObject, eventdata, handles)
% hObject    handle to mass0 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end



function nBounces_Callback(hObject, eventdata, handles)
% hObject    handle to nBounces (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of nBounces as text
%        str2double(get(hObject,'String')) returns contents of nBounces as a double
handles.n = str2double(get(hObject,'String'));
guidata(hObject,handles);

% --- Executes during object creation, after setting all properties.
function nBounces_CreateFcn(hObject, eventdata, handles)
% hObject    handle to nBounces (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


% --- Executes on selection change in smoothPop.
function smoothPop_Callback(hObject, eventdata, handles)
% hObject    handle to smoothPop (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: contents = cellstr(get(hObject,'String')) returns smoothPop contents as cell array
%        contents{get(hObject,'Value')} returns selected item from smoothPop
contents = {get(hObject,'Value')};
if contents{1} == 1
    handles.smoothBool = 1;
end
if contents{1} == 2
    handles.smoothBool = 0;
end

guidata(hObject,handles);


% --- Executes during object creation, after setting all properties.
function smoothPop_CreateFcn(hObject, eventdata, handles)
% hObject    handle to smoothPop (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: popupmenu controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end



function restit_Callback(hObject, eventdata, handles)
% hObject    handle to restit (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of restit as text
%        str2double(get(hObject,'String')) returns contents of restit as a double
handles.e = str2double(get(hObject,'String'));
guidata(hObject,handles);

% --- Executes during object creation, after setting all properties.
function restit_CreateFcn(hObject, eventdata, handles)
% hObject    handle to restit (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


% --- Executes on button press in RunPush.
function RunPush_Callback(hObject, eventdata, handles)
% hObject    handle to RunPush (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
[handles.time,handles.xDat,handles.yDat] = simulate_projectile(handles.x0, handles.y0, handles.vx0, handles.vy0, handles.mass, handles.radius, handles.smoothBool, handles.e, handles.n);

guidata(hObject,handles)

% --- Executes on selection change in popupmenu2.
function popupmenu2_Callback(hObject, eventdata, handles)
% hObject    handle to popupmenu2 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: contents = cellstr(get(hObject,'String')) returns popupmenu2 contents as cell array
%        contents{get(hObject,'Value')} returns selected item from popupmenu2
second = {get(hObject,'Value')};
if second{1} == 1
    handles.PLOTOPTION = 1;
elseif second{1} == 2
    handles.PLOTOPTION = 2;
else
    handles.PLOTOPTION = 3;
end

guidata(hObject,handles);


% --- Executes during object creation, after setting all properties.
function popupmenu2_CreateFcn(hObject, eventdata, handles)
% hObject    handle to popupmenu2 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: popupmenu controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


% --- Executes on button press in toPlotData.
function toPlotData_Callback(hObject, eventdata, handles)
% hObject    handle to toPlotData (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
plotOption = {get(hObject,'Value')};
if handles.PLOTOPTION == 1
    subplot(1,1,1,'Parent',handles.MainPanel)
    plot(handles.time,handles.xDat)
end

if handles.PLOTOPTION == 2
    subplot(1,1,1,'Parent',handles.MainPanel)
    plot(handles.time,handles.yDat)
    xlabel('Time (sec)')
    ylabel('Y Position (m)')
    
end

if handles.PLOTOPTION == 3
    subplot(1,1,1,'Parent',handles.MainPanel)
    plot(handles.xDat,handles.yDat)
end

guidata(hObject,handles);