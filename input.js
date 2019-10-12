const temp = require(&quot;heello&quot;);
const wow = require(&quot;heello&quot;);
import defaultExport from &quot;module-name&quot;;
import * as name from &quot;module-name&quot;;
import { hola } from &quot;module-name&quot;;
import { hola as alias } from &quot;module-name&quot;;
import { hola1 , hola2 } from &quot;module-name&quot;;
import { foo , bar } from &quot;module-name/path/to/specific/un-holaed/file&quot;;
import { hola1 , hola2 as alias2} from &quot;module-name&quot;;
import &quot;module-name&quot;;
const getTextStimuliData = (filterByParameters) =&gt; {
const query = mongo.textStimuliSchemaCollection.find();
Object.keys(filterByParameters).forEach((filter) =&gt; {
const filterValue = filterByParameters[filter];
query.where(filter).in(filterValue);
});
return query.exec();
};
const fetchTextStimuliWordData = (filterByParameters) =&gt; {
const query = mongo.textStimuliWordSchemaCollection.find();
Object.keys(filterByParameters).forEach((filter) =&gt; {
const filterValue = filterByParameters[filter];
if (filters === &#39;words&#39;) {
query.where(&#39;hii&#39;).in(filterValue);
} else {
query.where(filter).in(filterValue);
}
});
return query.exec();
};
const getTextStimuli = (rootObject, filterByParameters) =&gt; {
const filters = filterByParameters;
try {
if (filters.type) {
if (filters.type !== textStimuliType.WORD) {

return getTextStimuliData(filters);
}
delete filters.type;
return parseWordToTextStimuli(fetchTextStimuliWordData(filters));
}
return _.concat(
getTextStimuliData(filters),
parseWordToTextStimuli(fetchTextStimuliWordData(filters)),
);
} catch (e) {
throw Error(&#39;Error fetching textStimuli&#39;);
}
};