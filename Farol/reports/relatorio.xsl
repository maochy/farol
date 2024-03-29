<?xml version="1.0" encoding="ISO-8859-1" ?> 
<xsl:stylesheet xmlns:xsl="http://www.w3.org/1999/XSL/Transform" version="1.0">

<xsl:template match="/">

<html>

<head>
<title>Farol Tool - Ordenador de Classes para Teste de Integra��o</title>
</head>

<body>

<div align="center">
  <center>
  <table border="0" cellpadding="0" cellspacing="8" width="100%">

    <tr>
      <td valign="middle" width="100%">
      <p align="center"><span lang="pt"><font size="6" color="#0000FF">Ordena��o das Classes para 
      Teste de Integra��o</font></span></p>
      <p align="center"><i><font size="2">Gerado por Farol Tool</font></i></p></td>
      <td valign="middle" width="121"><font size="2"><strong>
      <img src="Coppe_Pesc.gif" width="106" height="111"></img></strong></font></td>
    </tr>

    <tr>

      <td valign="top" width="100%" colspan="2">
      <hr>
	</hr>
      <p align="left"><span lang="pt"><font size="5"><b><font color="#0000FF">
      Modelo: </font><i>
			<xsl:for-each select="IntegrationTest/Model">
				<xsl:value-of select="@name"/><br/>
			</xsl:for-each>
	</i></b></font></span></p>
      <p align="right"><span lang="pt"><font size="2"><b><i>Criado em: 
			<xsl:for-each select="IntegrationTest/Model">
				<xsl:value-of select="@date"/><br/>
			</xsl:for-each>
</i></b></font></span></p>
      <p align="center"><u><i><b><span lang="pt"><font size="5">Descri��o das Classes</font></span></b></i></u></p>

      <table border="2" cellpadding="0" cellspacing="0" style="border-collapse: collapse" bordercolor="#111111" width="100%" id="AutoNumber2">
        <tr>
          <td width="56%" align="center" bgcolor="#C0C0C0"><b><span lang="pt">
          <font size="4" color="#0000FF">Nome</font></span></b></td>
          <td width="16%" align="center" bgcolor="#C0C0C0"><b><span lang="pt">
          <font size="4" color="#0000FF">Tamanho</font></span></b></td>
          <td width="28%" align="center" bgcolor="#C0C0C0"><b><span lang="pt">
          <font size="4" color="#0000FF">Fator de Influ�ncia</font></span></b></td>
        </tr>        <tr>
          <td width="56%"><p align="center"><span lang="pt">
			<xsl:for-each select="IntegrationTest/Model/Class">
				<xsl:value-of select="@name"/><br/>
			</xsl:for-each>
	  </span></p></td>
          <td width="16%" align="center"><span lang="pt">
			<xsl:for-each select="IntegrationTest/Model/Class">
				<xsl:value-of select="@size"/><br/>
			</xsl:for-each>
	  </span></td>
          <td width="28%" align="center"><span lang="pt">
			<xsl:for-each select="IntegrationTest/Model/Class">
				<xsl:value-of select="@fit"/><br/>
			</xsl:for-each>
	  </span></td>
        </tr>
      </table>
    
      <p align="center"><u><i><b><span lang="pt"><font size="5">Ordem de Integra��o</font></span></b></i></u></p>
      <div align="center">
        <center>

        <table border="2" cellpadding="0" cellspacing="0" style="border-left:.75pt solid black; border-right:.75pt solid black; border-top:1.5pt solid black; border-bottom:1.5pt solid black; " width="100%" id="AutoNumber1" fpstyle="7,011110010" height="52">
          <tr>
            <td width="71%" style="color: black; border-style: solid; border-width: 1; background-color: #C0C0C0" height="18">
            <p align="center"><b><span lang="pt"><font size="4" color="#0000FF">
            Nome da Classe</font></span></b></p></td>
            <td width="129%" style="color: black; border-style: solid; border-width: 1; background-color: #C0C0C0" height="18">
            <p align="center"><b><span lang="pt"><font size="4" color="#0000FF">
            Quantidade de Stubs</font></span></b></p></td>
          </tr>

	<xsl:for-each select="IntegrationTest/Result/Order/Class">
          <tr>
            <td width="71%" style="color: black; border-style: solid; border-width: 1; background-color: white" height="1">
            <p align="center"><span lang="pt">

		<xsl:value-of select="@name"/><br/>
		</span></p></td>
            <td width="129%" style="color: black; border-style: solid; border-width: 1; background-color: white" height="1">
            <p align="center"><span lang="pt"> (

		<xsl:value-of select="@stubs"/>
				<xsl:for-each select="Stubs">
					, <xsl:value-of select="@name"/>
				</xsl:for-each> )	
		</span></p></td>
          </tr>
      </xsl:for-each>

      </table>

        </center>
      </div>







                <table border="2" cellpadding="0" cellspacing="0" style="border-collapse: collapse" bordercolor="#111111" width="100%" id="AutoNumber3">
                  <tr>
            <td width="200%" style="color: navy; border-style: solid; border-width: 1; background-color: #C0C0C0" height="17" align="center" colspan="2">
            <b><font size="4" color="#0000FF">Ordem modificada</font></b></td>
                  </tr>
                  <tr>
            <td width="71%" style="color: navy; border-style: solid; border-width: 1; background-color: #E2E2E2" height="17" align="justify">
            <p style="margin-top: 0; margin-bottom: 0">
            <font size="4" color="#0000FF"><b>     N�mero de Stubs</b></font></p></td>
            <td width="129%" style="color: navy; border-style: solid; border-width: 1; background-color: #E2E2E2" height="17" align="center">
            <font color="#000000"><b>

				<xsl:for-each select="IntegrationTest/Result/Final">
					<xsl:value-of select="@stubs"/><br/>
				</xsl:for-each>

		
		
		</b></font></td>
                  </tr>
                  <tr>
            <td width="71%" style="color: navy; border-style: solid; border-width: 1; background-color: #E2E2E2" height="17" align="justify">
            <p style="margin-top: 0; margin-bottom: 0">
            <font size="4" color="#0000FF"><b>     
            Tamanho</b></font></p></td>
            <td width="129%" style="color: navy; border-style: solid; border-width: 1; background-color: #E2E2E2" height="17" align="center">
            <font color="#000000"><b>

				<xsl:for-each select="IntegrationTest/Result/Final">
					<xsl:value-of select="@complexity"/><br/>
				</xsl:for-each>


		</b></font></td>
                  </tr>
                  <tr>
            <td width="200%" style="color: navy; border-style: solid; border-width: 1; background-color: #C0C0C0" height="17" align="center" colspan="2">
            <font size="4" color="#0000FF"><b>Ordem original</b></font></td>
                  </tr>
                  <tr>
            <td width="71%" style="color: navy; border-style: solid; border-width: 1; background-color: #E2E2E2" height="17" align="justify">
            <font size="4" color="#0000FF"><b>     N�mero de 
            Stubs</b></font></td>
            <td width="129%" style="color: navy; border-style: solid; border-width: 1; background-color: #E2E2E2" height="17" align="center">
            <font color="#000000"><b>

				<xsl:for-each select="IntegrationTest/Result/Source">
					<xsl:value-of select="@stubs"/><br/>
				</xsl:for-each>


</b></font></td>
                  </tr>
                  <tr>
            <td width="71%" style="color: navy; border-style: solid; border-width: 1; background-color: #E2E2E2" height="17" align="justify">
            <font size="4" color="#0000FF"><b> 
            Tamanho</b></font></td>
            <td width="129%" style="color: navy; border-style: solid; border-width: 1; background-color: #E2E2E2" height="17" align="center">
            <font color="#000000"><b>

				<xsl:for-each select="IntegrationTest/Result/Source">
					<xsl:value-of select="@complexity"/><br/>
				</xsl:for-each>


</b></font></td>
                  </tr>
                </table>

				<table id="toolbar" align="center" cellspacing='5' cellpadding="4" >
					<tr>
					<th align="center"> <a class="toolbar" href="javascript:window.print();"><img border='0' src='printer.png' width='32' height='32'/><br/>Imprimir</a>
					</th>
					<th align="center"><a class="toolbar" href="javascript:window.close();"><img border='0' src='cancel_f2.png' width='32' height='32'/><br/>Cancelar</a>
					</th>
					</tr>
				</table>

                <hr>
                <p style="margin-bottom: 0" align="right"><i><span lang="pt">
                <font size="2">Grupo de Engenharia de Software Experimental - 
                COPPE/UFRJ</font></span></i></p>
                <p style="margin-top: 0" align="right"><i><span lang="pt">
                <font size="2" color="#0000FF">
                <a href="http://www.cos.ufrj.br/~ese">
                http://www.cos.ufrj.br/~ese</a></font></span></i></p></hr></td>
    </tr>
  </table>

  </center>
</div>

</body>

</html>

</xsl:template>

</xsl:stylesheet>
