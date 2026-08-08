namespace AutoCore.Utils.Logging;

using System.Text;
using System.Text.Json;

/// <summary>
/// Serializes a <see cref="StructuredLogRecord"/> to one line of NDJSON.
/// <para>
/// Total function (SS-06): called from catch blocks, so hostile property values
/// (throwing <c>ToString()</c>, NaN, unknown types) degrade to marker strings and the
/// serializer itself never throws.
/// </para>
/// <para>
/// The envelope keys (<c>Timestamp</c>, <c>Level</c>, <c>EventName</c>, <c>Message</c>,
/// <c>Audit</c>) are reserved; a property using one of those names is skipped rather than
/// producing duplicate JSON keys.
/// </para>
/// </summary>
/// <summary>Public for bug-report packaging and tests; total (never throws).</summary>
public static class NdjsonSerializer
{
    private static readonly HashSet<string> ReservedKeys = new(StringComparer.Ordinal)
    {
        "Timestamp", "Level", "EventName", "Message", "Audit"
    };

    public static string Serialize(StructuredLogRecord record)
    {
        try
        {
            return SerializeCore(record);
        }
        catch (Exception ex)
        {
            // Last resort: a hand-built minimal line so the failure itself is still visible.
            var safeEvent = record?.EventName ?? "null";
            return "{\"Timestamp\":\"" + DateTime.UtcNow.ToString("yyyy-MM-ddTHH:mm:ss.fffZ") +
                   "\",\"Level\":\"ERROR\",\"EventName\":\"SerializerFailure\",\"FailedEvent\":\"" +
                   JsonEncodedText.Encode(safeEvent) + "\",\"ExceptionType\":\"" + ex.GetType().Name + "\"}";
        }
    }

    private static string SerializeCore(StructuredLogRecord record)
    {
        using var stream = new MemoryStream(256);
        using (var writer = new Utf8JsonWriter(stream))
        {
            writer.WriteStartObject();

            writer.WriteString("Timestamp", record.TimestampUtc.ToString("yyyy-MM-ddTHH:mm:ss.fffffffZ"));
            writer.WriteString("Level", DescribeLevel(record.Level));
            writer.WriteString("EventName", record.EventName ?? StructuredLogRecord.UnnamedEvent);

            if (record.Message != null)
                writer.WriteString("Message", record.Message);

            if (record.Audit)
                writer.WriteBoolean("Audit", true);

            var written = new HashSet<string>(StringComparer.Ordinal);

            foreach (var pair in record.Properties)
            {
                if (string.IsNullOrEmpty(pair.Key) || ReservedKeys.Contains(pair.Key) || !written.Add(pair.Key))
                    continue;

                WriteValue(writer, pair.Key, pair.Value);
            }

            writer.WriteEndObject();
        }

        return Encoding.UTF8.GetString(stream.ToArray());
    }

    internal static string DescribeLevel(StructuredLogLevel level) => level switch
    {
        StructuredLogLevel.Trace => "TRACE",
        StructuredLogLevel.Debug => "DEBUG",
        StructuredLogLevel.Info => "INFO",
        StructuredLogLevel.Warning => "WARN",
        StructuredLogLevel.Error => "ERROR",
        StructuredLogLevel.Fatal => "FATAL",
        _ => $"LEVEL({(int)level})"
    };

    private static void WriteValue(Utf8JsonWriter writer, string key, object value)
    {
        switch (value)
        {
            case null:
                writer.WriteNull(key);
                return;
            case string s:
                writer.WriteString(key, s);
                return;
            case bool b:
                writer.WriteBoolean(key, b);
                return;
            case byte or sbyte or short or ushort or int or uint or long:
                writer.WriteNumber(key, Convert.ToInt64(value));
                return;
            case ulong ul:
                writer.WriteNumber(key, ul);
                return;
            case float f:
                WriteFloatingPoint(writer, key, f);
                return;
            case double d:
                WriteFloatingPoint(writer, key, d);
                return;
            case decimal m:
                writer.WriteNumber(key, m);
                return;
            case Guid g:
                writer.WriteString(key, g.ToString());
                return;
            case DateTime dt:
                writer.WriteString(key, dt.ToUniversalTime().ToString("yyyy-MM-ddTHH:mm:ss.fffZ"));
                return;
            case TimeSpan ts:
                writer.WriteString(key, ts.ToString());
                return;
            case Enum e:
                writer.WriteString(key, e.ToString());
                return;
            default:
                writer.WriteString(key, DescribeUnknown(value));
                return;
        }
    }

    private static void WriteFloatingPoint(Utf8JsonWriter writer, string key, double value)
    {
        if (double.IsFinite(value))
            writer.WriteNumber(key, value);
        else
            writer.WriteString(key, value.ToString());
    }

    private static string DescribeUnknown(object value)
    {
        try
        {
            return value.ToString() ?? "null";
        }
        catch (Exception ex)
        {
            return $"<unserializable:{value.GetType().Name}:{ex.GetType().Name}>";
        }
    }
}
