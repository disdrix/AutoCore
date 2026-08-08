using System.IO.Compression;
using System.Text;
using AutoCore.Game.Diagnostics;
using AutoCore.Game.Entities;
using AutoCore.Game.Structures;
using AutoCore.Utils.Logging;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace AutoCore.Game.Tests.Diagnostics;

[TestClass]
public class BugReportBuilderTests
{
    [TestInitialize]
    public void Init()
    {
        GameLog.ResetForTests();
        GameLog.SetSinkForTests(new AutoCore.Game.Tests.Fakes.InMemoryLogSink());
        GameLog.MinimumLevel = StructuredLogLevel.Trace;
        PlayerActionTraceBuffer.Clear();
        BugReportUploadBridge.Clear();
        BugReportService.ResetForTests();
    }

    [TestCleanup]
    public void Cleanup()
    {
        GameLog.ResetForTests();
        LogContext.ClearForTests();
        PlayerActionTraceBuffer.Clear();
        BugReportUploadBridge.Clear();
        BugReportService.ResetForTests();
    }

    [TestMethod]
    public void Build_IncludesDescriptionMissionJournalAndEvents()
    {
        var character = new Character();
        character.SetCoid(9001, true);
        character.SetMissionsForTests(
            new[]
            {
                new AutoCore.Database.Char.Models.CharacterQuestData
                {
                    CharacterCoid = 9001,
                    MissionId = 42,
                    ActiveObjectiveSequence = 0,
                    State = 1,
                    ObjectiveProgress = new byte[] { 1, 0 },
                }
            },
            new[]
            {
                new AutoCore.Database.Char.Models.CharacterCompletedMissionData
                {
                    CharacterCoid = 9001,
                    MissionId = 7,
                }
            });

        using (LogContext.Push(("SessionId", "sess-bug"), ("CharacterId", 9001L)))
        {
            for (var i = 0; i < 3; i++)
                GameLog.Audit("CurrencyChanged", ("Delta", i), ("i", i));
        }

        var package = BugReportBuilder.Build(character, "wheels fell off near Gunny");

        Assert.IsFalse(string.IsNullOrWhiteSpace(package.ReportId));
        Assert.IsTrue(package.FileName.EndsWith(".zip", StringComparison.OrdinalIgnoreCase));
        Assert.IsTrue(package.ZipBytes.Length > 50);
        StringAssert.Contains(package.DiscordMessage, "wheels fell off");
        StringAssert.Contains(package.DiscordMessage, "9001");

        using var ms = new MemoryStream(package.ZipBytes);
        using var zip = new ZipArchive(ms, ZipArchiveMode.Read);
        var names = zip.Entries.Select(e => e.FullName).OrderBy(x => x).ToList();
        CollectionAssert.Contains(names, "README.txt");
        CollectionAssert.Contains(names, "description.txt");
        CollectionAssert.Contains(names, "mission-journal.txt");
        CollectionAssert.Contains(names, "snapshot.json");
        CollectionAssert.Contains(names, "player-events.ndjson");

        var journal = ReadEntry(zip, "mission-journal.txt");
        StringAssert.Contains(journal, "42");
        StringAssert.Contains(journal, "7");

        var desc = ReadEntry(zip, "description.txt");
        StringAssert.Contains(desc, "wheels fell off");

        var events = ReadEntry(zip, "player-events.ndjson");
        StringAssert.Contains(events, "CurrencyChanged");
        Assert.IsTrue(events.Split('\n', StringSplitOptions.RemoveEmptyEntries).Length >= 3);
    }

    [TestMethod]
    public void Submit_WhenUploaderMissing_FailsGracefully()
    {
        var character = new Character();
        character.SetCoid(1, true);
        var result = BugReportService.Submit(character, "test");
        Assert.IsFalse(result.Success);
        StringAssert.Contains(result.PlayerMessage, "not available");
    }

    [TestMethod]
    public void Submit_WhenUploaderReady_QueuesUploadAndReturnsOk()
    {
        var fake = new FakeBugReportUploader { Available = true };
        BugReportUploadBridge.Uploader = fake;
        BugReportService.CooldownSeconds = 0;

        var character = new Character();
        character.SetCoid(55, true);

        var result = BugReportService.Submit(character, "client freezes on warp");
        Assert.IsTrue(result.Success);
        StringAssert.Contains(result.PlayerMessage, "submitted");

        // Upload is fire-and-forget; wait briefly.
        var deadline = DateTime.UtcNow.AddSeconds(2);
        while (fake.Packages.Count == 0 && DateTime.UtcNow < deadline)
            Thread.Sleep(20);

        Assert.AreEqual(1, fake.Packages.Count);
        Assert.IsTrue(fake.Packages[0].ZipBytes.Length > 0);
        StringAssert.Contains(fake.Packages[0].DiscordMessage, "client freezes");
    }

    [TestMethod]
    public void Submit_Cooldown_BlocksSecondReport()
    {
        var fake = new FakeBugReportUploader { Available = true };
        BugReportUploadBridge.Uploader = fake;
        BugReportService.CooldownSeconds = 120;

        var character = new Character();
        character.SetCoid(77, true);

        Assert.IsTrue(BugReportService.Submit(character, "first").Success);
        var second = BugReportService.Submit(character, "second");
        Assert.IsFalse(second.Success);
        StringAssert.Contains(second.PlayerMessage, "wait");
    }

    [TestMethod]
    public void ChatCommand_ReportBug_IsHandled()
    {
        var fake = new FakeBugReportUploader { Available = true };
        BugReportUploadBridge.Uploader = fake;
        BugReportService.CooldownSeconds = 0;

        var character = new Character();
        character.SetCoid(88, true);
        character.GMLevel = 0; // must work for non-GM players

        var result = AutoCore.Game.Chat.ChatCommandService.Instance.Execute(
            character, "/reportbug mission marker stuck on map");

        Assert.IsTrue(result.Handled);
        StringAssert.Contains(result.Message, "submitted");
    }

    private static string ReadEntry(ZipArchive zip, string name)
    {
        var entry = zip.GetEntry(name);
        Assert.IsNotNull(entry, name);
        using var s = entry!.Open();
        using var r = new StreamReader(s, Encoding.UTF8);
        return r.ReadToEnd();
    }

    private sealed class FakeBugReportUploader : IBugReportUploader
    {
        public bool Available { get; set; }
        public bool IsAvailable => Available;
        public List<BugReportPackage> Packages { get; } = new();

        public Task<BugReportSubmitResult> UploadAsync(BugReportPackage package, CancellationToken cancellationToken = default)
        {
            Packages.Add(package);
            return Task.FromResult(BugReportSubmitResult.Ok());
        }
    }
}
