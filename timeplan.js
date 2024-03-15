function toggleContent(id)
{
    var content = document.getElementById(id);
    if (content.style.display === "none" || content.style.display === "")
    {
        content.style.display = "block";
    }
    
    else
    {
        content.style.display = "none";
    }
}

document.addEventListener("DOMContentLoaded", function ()
{
    var phases = document.getElementsByClassName("toggle");
    for (var i = 0; i < phases.length; i++)
    {
        var phaseId = phases[i].nextElementSibling.id;
        document.getElementById(phaseId).style.display = "none";
    }
});