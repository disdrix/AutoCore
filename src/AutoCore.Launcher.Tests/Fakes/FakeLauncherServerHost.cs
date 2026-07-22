namespace AutoCore.Launcher.Tests.Fakes;

using AutoCore.Launcher.Bootstrap;

internal sealed class FakeLauncherServerHost : ILauncherServerHost
{
    private readonly bool _startSucceeds;
    private readonly Action? _onShutdown;
    private readonly List<string>? _eventLog;

    public FakeLauncherServerHost(
        string name,
        bool startSucceeds = true,
        List<string>? eventLog = null,
        Action? onShutdown = null)
    {
        Name = name;
        _startSucceeds = startSucceeds;
        _eventLog = eventLog;
        _onShutdown = onShutdown;
    }

    public string Name { get; }

    public bool IsStarted { get; private set; }

    public bool IsShutdown { get; private set; }

    public int SetupCount { get; private set; }

    public int StartCount { get; private set; }

    public int ShutdownCount { get; private set; }

    public void Setup()
    {
        SetupCount++;
        _eventLog?.Add($"{Name}.Setup");
    }

    public bool Start()
    {
        StartCount++;
        _eventLog?.Add($"{Name}.Start");
        IsStarted = _startSucceeds;
        return _startSucceeds;
    }

    public void Shutdown()
    {
        ShutdownCount++;
        _eventLog?.Add($"{Name}.Shutdown");
        _onShutdown?.Invoke();
        IsShutdown = true;
        IsStarted = false;
    }
}
