using System.Diagnostics.CodeAnalysis;
using System.Net;

namespace AutoCore.Auth.Network;

using AutoCore.Utils.Networking;
using AutoCore.Utils;

public partial class AuthServer
{
    /// <summary>Raw TCP bind/accept for auth clients — requires live ports; client lifecycle covered via unit-test harness.</summary>
    [ExcludeFromCodeCoverage(Justification = "Raw TCP bind/accept on live ports; AuthClient lifecycle covered via test-seam constructor.")]
    private void StartListening()
    {
        ListenerSocket.OnAccept += OnAccept;
        ListenerSocket.StartListening(new IPEndPoint(IPAddress.Any, Config.AuthSocketPort));

        Logger.WriteLog(LogType.Network, "*** Listening for clients on port {0}", Config.AuthSocketPort);
    }

    [ExcludeFromCodeCoverage(Justification = "Raw accept callback; AuthClient construction/handling covered via test seams.")]
    private void OnAccept(AsyncLengthedSocket newSocket)
    {
        if (newSocket == null)
            return;

        lock (Clients)
            Clients.Add(new AuthClient(newSocket, this));
    }
}
