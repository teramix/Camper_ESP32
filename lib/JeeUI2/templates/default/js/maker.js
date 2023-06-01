var json = "none";
var page = 0;
var obj;
var app;
var pages;

function make(){
    obj = JSON.parse(json);
    app = obj.app;
    pages = obj.menu.length;
    menu();
    content();
}

function parse(){
    var xhr = new XMLHttpRequest();
    xhr.open('GET', '/echo', true);
    xhr.onload = function () {
        json = xhr.responseText;
        make();
    };
    xhr.send(null);
}

function new_page(p){
    page = p;
    menu();
    content();
}

function inner(id, content){
    document.getElementById(id).innerHTML += content;
}

function menu_item(name, current, p){
    if (!current)
        return "<li class=\"pure-menu-item\" onclick=\"new_page(" + p + ")\"><a href=\"#\" class=\"pure-menu-link\">" + name + "</a></li>";
    else
        return "<li class=\"pure-menu-item menu-item-divided pure-menu-selected\" onclick=\"new_page(" + p + ")\"><a href=\"#\" class=\"pure-menu-link\">" + name + "</a></li>";
}

function menu(){
    var content = "<div class=\"pure-menu\"><a class=\"pure-menu-heading\" href=\"#\">" + app + "</a><ul class=\"pure-menu-list\">";
    for(var i = 0; i < pages; i++){
        var current;
        if(page == i) current = true;
        else current = false;
        content += menu_item(obj.menu[i], current, i);
    }
    content += "</ul></div>";
    document.getElementById("menu").innerHTML = content;
}

function content(){
    document.getElementById("main").innerHTML = "";
    var content = "<div class=\"header\"><h1>" + obj.menu[page] + "</h1></div>";
    content += "<div class=\"content\">";
    content += "<form class=\"pure-form pure-form-stacked\">";
    content += "<fieldset>";
    content += "<div class=\"pure-g\">";

    var items = obj.content[page].length;
    for(var i = 0; i < items; i++){
        content += content_item(obj.content[page][i], i);
    }

    content += "</div>";
    content += "</fieldset>";
    content += "</form>";
    content += "</div>";
    document.getElementById("main").innerHTML = content;
}

function content_item(item, i){


    var content = "<div class=\"pure-u-1 pure-u-md-1-3\">";

    var html = item.html;

    if (html == "input" && item.type == 'range') content += "<label id=\"" + item.id + "-val\">" + item.label + " " + item.value + "</label>";
    else if (item.type == "checkbox") content += "<label class=\"pure-checkbox\">";
    else if (html == "button") content += "<br>";
    else  content += "<label id=\"" + item.id + "-val\">" + item.label + "</label>";



    switch (html) {
        case "input":
            content += "<input ";
            if (typeof item.type == 'string') content += "type=\"" + item.type + "\"";
            if (typeof item.id == 'string') content += "id=\"" + item.id + "\"";
            if (typeof item.name == 'string') content += "name=\"" + item.name + "\"";
            if (typeof item.min == 'string') content += "min=\"" + item.min + "\"";
            if (typeof item.max == 'string') content += "max=\"" + item.max + "\"";
            if (typeof item.step == 'string') content += "step=\"" + item.step + "\"";
            if (typeof item.value == 'string') content += "value=\"" + item.value + "\"";
            if (typeof item.placeholder == 'string') content += "placeholder=\"" + item.placeholder + "\"";

            if (item.type != "checkbox") content += "class=\"pure-u-24-24\" maxlength=\"255\"";
            if (item.type == "checkbox" && item.value == 'true') content += " checked ";

            if (item.type != "range") content += "oninput=\"data('" + item.type + "', this.id, this.value, '" + item.label + "', " + page + ", " + i + ")\"";
            if (item.type == "range") content += "oninput=\"datarange(this.id, this.value, '" + item.label + "')\" onchange=\"data('" + item.type + "', this.id, this.value, '" + item.label + "', " + page + ", " + i + ")\"";
            content += ">";

            if (item.type == "checkbox") content += "&nbsp" + item.label + "</label>";
            break;

        case "select":
            content += "<select ";
            if (typeof item.id == 'string') content += "id=\"" + item.id + "\"";
            if (typeof item.name == 'string') content += "name=\"" + item.name + "\"";
            if (typeof item.value == 'string') content += "value=\"" + item.value + "\"";
            content += "class=\"pure-u-24-24\"";
            content += "oninput=\"data(" + item.type + ", this.id, this.value, '" + item.label + "', '" + page + "', '" + i + "')\"";
            content += ">";
            for(var i = 0; i < item.options.length; i++){
                if (item.options[i].value == item.value) content += "<option value=\"" + item.options[i].value + "\" selected>";
                else content += "<option value=\"" + item.options[i].value + "\">";
                content += item.options[i].label;
                content += "</option >";
            }
            content += "</select>";
            break;

            case "button":
                    content += "<input type=\"button\" ";
                    content += "id=\"" + item.id + "\" value=\"" + item.label + "\" class=\"pure-button pure-button-primary\" onclick=\"data('" + item.type + "', this.id, this.value, '" + item.label + "', " + page + ", " + i + ")\">";
                    //content += item.label;
                    //content += "</button>";


                    break;
    
        default:
            break;
    }
    content += "</div>";
    return content;
}

function datarange(id, value, label){
    document.getElementById(id + "-val").innerHTML = label + ":&nbsp" + value;
}

function data(type, id, value, label, page, i){
    if (type == "range") document.getElementById(id + "-val").innerHTML = label + ":&nbsp" + value;
    if (type == "text") document.getElementById(id + "-val").innerHTML = label + "&nbsp(" + value.length + ")";

    if (type == "checkbox"){
        var chbox=document.getElementById(id);
        if (chbox.checked) value = "true";
        else  value = "false";
    }
    obj.content[page][i].value = value;
    send(id, value)
}

function send(id, value){
    var formData = new FormData();
    formData.append(id, value);
    var xhr = new XMLHttpRequest();
    xhr.open('POST', '/post', true);
    xhr.onload = function () {
        var res = xhr.responseText;
    };
    xhr.send(formData);
}