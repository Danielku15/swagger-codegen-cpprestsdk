package io.swagger.codegen.languages;

import io.swagger.codegen.*;
import io.swagger.models.Model;
import io.swagger.models.properties.*;

import java.util.*;
import java.io.File;

public class CpprestsdkGenerator extends DefaultCodegen implements CodegenConfig {

	/**
	 * Configures the type of generator.
	 * 
	 * @return the CodegenType for this generator
	 * @see io.swagger.codegen.CodegenType
	 */
	public CodegenType getTag() {
		return CodegenType.CLIENT;
	}

	/**
	 * Configures a friendly name for the generator. This will be used by the
	 * generator to select the library with the -l flag.
	 * 
	 * @return the friendly name for the generator
	 */
	public String getName() {
		return "cpprestsdk";
	}

	/**
	 * Returns human-friendly help for the generator. Provide the consumer with
	 * help tips, parameters here
	 * 
	 * @return A string value for the help message
	 */
	public String getHelp() {
		return "Generates a cpprestsdk client library.";
	}

	public CpprestsdkGenerator() {
		super();

		modelTemplateFiles.put("model-header.mustache", ".h");
		modelTemplateFiles.put("model-source.mustache", ".cpp");

		apiTemplateFiles.put("api-header.mustache", ".h");
		apiTemplateFiles.put("api-source.mustache", ".cpp");

		templateDir = "cpprestsdk";

		reservedWords = new HashSet<String>();

		supportingFiles.add(new SupportingFile("modelbase-header.mustache", "", "ModelBase.h"));
		supportingFiles.add(new SupportingFile("modelbase-source.mustache", "", "ModelBase.cpp"));
		supportingFiles.add(new SupportingFile("httpcontent-header.mustache", "", "HttpContent.h"));
		supportingFiles.add(new SupportingFile("httpcontent-source.mustache", "", "HttpContent.cpp"));
		supportingFiles.add(new SupportingFile("multipart-header.mustache", "", "MultipartFormData.h"));
		supportingFiles.add(new SupportingFile("multipart-source.mustache", "", "MultipartFormData.cpp"));
		supportingFiles.add(new SupportingFile("object-header.mustache", "", "Object.h"));
		supportingFiles.add(new SupportingFile("object-source.mustache", "", "Object.cpp"));

		languageSpecificPrimitives = new HashSet<String>(
				Arrays.asList("int", "char", "bool", "long", "float", "double", "int32_t", "int64_t"));

		typeMapping = new HashMap<String, String>();
		typeMapping.put("date", "utility::datetime");
		typeMapping.put("DateTime", "utility::datetime");
		typeMapping.put("string", "utility::string_t");
		typeMapping.put("integer", "int32_t");
		typeMapping.put("long", "int64_t");
		typeMapping.put("boolean", "bool");
		typeMapping.put("array", "std::vector");
		typeMapping.put("map", "std::map");
		typeMapping.put("file", "HttpContent");
		typeMapping.put("object", "Object");
		typeMapping.put("binary", "std::string");

		super.importMapping = new HashMap<String, String>();
		importMapping.put("std::vector", "#include <vector>");
		importMapping.put("std::map", "#include <map>");
		importMapping.put("std::string", "#include <string>");
		importMapping.put("HttpContent", "#include \"HttpContent.h\"");
		importMapping.put("Object", "#include \"Object.h\"");
		importMapping.put("utility::string_t", "#include <cpprest/details/basic_types.h>");
		importMapping.put("utility::datetime", "#include <cpprest/details/basic_types.h>");
	}

	/**
	 * Escapes a reserved word as defined in the `reservedWords` array. Handle
	 * escaping those terms here. This logic is only called if a variable
	 * matches the reseved words
	 * 
	 * @return the escaped term
	 */
	@Override
	public String escapeReservedWord(String name) {
		return "_" + name; // add an underscore to the name
	}

	/**
	 * Location to write model files. You can use the modelPackage() as defined
	 * when the class is instantiated
	 */
	public String modelFileFolder() {
		return outputFolder + "/model";
	}

	/**
	 * Location to write api files. You can use the apiPackage() as defined when
	 * the class is instantiated
	 */
	@Override
	public String apiFileFolder() {
		return outputFolder + "/client";
	}

	@Override
	public String toModelImport(String name) {
		if (importMapping.containsKey(name)) {
			return importMapping.get(name);
		} else {
			return "#include \"" + name + ".h\"";
		}
	}

	@Override
	public CodegenModel fromModel(String name, Model model, Map<String, Model> allDefinitions) {
		CodegenModel codegenModel = super.fromModel(name, model, allDefinitions);

		Set<String> oldImports = codegenModel.imports;
		codegenModel.imports = new HashSet<String>();
		for (String imp : oldImports) {
			String newImp = toModelImport(imp);
			if(!newImp.isEmpty()){
				codegenModel.imports.add(newImp);	
			}
		}

		return codegenModel;
	}

	@Override
	public String toModelFilename(String name) {
		return initialCaps(name);
	}

	@Override
	public String toApiFilename(String name) {
		return initialCaps(name) + "Client";
	}

	/**
	 * Optional - type declaration. This is a String which is used by the
	 * templates to instantiate your types. There is typically special handling
	 * for different property types
	 *
	 * @return a string value used as the `dataType` field for model templates,
	 *         `returnType` for api templates
	 */
	@Override
	public String getTypeDeclaration(Property p) {
		String swaggerType = getSwaggerType(p);

		if (p instanceof ArrayProperty) {
			ArrayProperty ap = (ArrayProperty) p;
			Property inner = ap.getItems();
			return getSwaggerType(p) + "<" + getTypeDeclaration(inner) + ">";
		}
		if (p instanceof MapProperty) {
			MapProperty mp = (MapProperty) p;
			Property inner = mp.getAdditionalProperties();
			return getSwaggerType(p) + "<utility::string_t, " + getTypeDeclaration(inner) + ">";
		}
		if (p instanceof StringProperty || p instanceof DateProperty || p instanceof DateTimeProperty
				|| languageSpecificPrimitives.contains(swaggerType)) {
			return toModelName(swaggerType);
		}

		return "std::shared_ptr<" + swaggerType + ">";
	}

	@Override
	public String toDefaultValue(Property p) {
		if (p instanceof StringProperty) {
			return "U(\"\")";
		} else if (p instanceof BooleanProperty) {
			return "false";
		} else if (p instanceof DateProperty) {
			return "utility::datetime()";
		} else if (p instanceof DateTimeProperty) {
			return "utility::datetime()";
		} else if (p instanceof DoubleProperty) {
			return "0.0";
		} else if (p instanceof FloatProperty) {
			return "0.0f";
		} else if (p instanceof IntegerProperty) {
			return "0";
		} else if (p instanceof LongProperty) {
			return "0L";
		} else if (p instanceof DecimalProperty) {
			return "0.0";
		} else if (p instanceof MapProperty) {
			MapProperty ap = (MapProperty) p;
			String inner = getSwaggerType(ap.getAdditionalProperties());
			return "std::map<utility::string_t, " + inner + ">()";
		} else if (p instanceof ArrayProperty) {
			ArrayProperty ap = (ArrayProperty) p;
			String inner = getSwaggerType(ap.getItems());
			if (!languageSpecificPrimitives.contains(inner)) {
				inner = "std::shared_ptr<" + inner + ">";
			}
			return "std::vector<" + inner + ">()";
		} else if (p instanceof RefProperty) {
			RefProperty rp = (RefProperty) p;
			return "std::shared_ptr<new " + toModelName(rp.getSimpleRef()) + ">";
		}
		return "nullptr";
	}

	/**
	 * Optional - swagger type conversion. This is used to map swagger types in
	 * a `Property` into either language specific types via `typeMapping` or
	 * into complex models if there is not a mapping.
	 *
	 * @return a string value of the type or complex model for this property
	 * @see io.swagger.models.properties.Property
	 */
	@Override
	public String getSwaggerType(Property p) {
		String swaggerType = super.getSwaggerType(p);
		String type = null;
		if (typeMapping.containsKey(swaggerType)) {
			type = typeMapping.get(swaggerType);
			if (languageSpecificPrimitives.contains(type))
				return toModelName(type);
		} else
			type = swaggerType;
		return toModelName(type);
	}

	@Override
	public String toModelName(String type) {
		if (typeMapping.keySet().contains(type) || typeMapping.values().contains(type)
				|| importMapping.values().contains(type) || defaultIncludes.contains(type)
				|| languageSpecificPrimitives.contains(type)) {
			return type;
		} else {
			return Character.toUpperCase(type.charAt(0)) + type.substring(1);
		}
	}

	@Override
	public String toVarName(String name) {
		if (typeMapping.keySet().contains(name) || typeMapping.values().contains(name)
				|| importMapping.values().contains(name) || defaultIncludes.contains(name)
				|| languageSpecificPrimitives.contains(name)) {
			return name;
		}

		if (name.length() > 1) {
			return Character.toUpperCase(name.charAt(0)) + name.substring(1);
		}

		return name;
	}

	@Override
	public String toApiName(String type) {
		return Character.toUpperCase(type.charAt(0)) + type.substring(1) + "Client";
	}
}