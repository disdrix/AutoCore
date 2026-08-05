# Review B (skeptical / adversarial): `aa_008073b0` Client_SendGlobalPacket

| Field | Value |
|---|---|
| **Stable ID** | `aa_008073b0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY dual W18-B) |
| **Counterpart** | `reviews/A_aa_008073b0_Client_SendGlobalPacket.md` |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `read_memory` only.

---

## 1. Claims under attack

| # | Claim | Result |
|---|---|---|
| 1 | Same ABI as `Client_SendSectorPacket` (ECX thiscall) | **Falsified** — body uses **ESI** only; sector uses **ECX** |
| 2 | Null conn silent drop like sector | **Falsified** — returns **`0x80004005`** |
| 3 | Reliability from live-in EAX | **Falsified** — push **0** constant; no SHR/NOT |
| 4 | Always returns 0 | **Falsified** — success 0, fail E_FAIL |
| 5 | No pre-send gate | **Falsified** — **vtbl+0x08** must be true |
| 6 | Conn at +0xc78 | **Falsified** — **`+0xc7c`** only |
| 7 | Encrypts / builds opcode here | **Falsified** — pure transport passthrough |
| 8 | Decompiler `unaff_ESI` is noise | **Falsified** — bytes bind client to ESI |
| 9 | Product symbol known | **Unproven** — name is role-based sibling of sector send |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| ESI client + ret 8 | **High** | Call convention bug in ports / hooks |
| +0xc7c global conn | **High** | Send on wrong channel |
| Ready vtbl+8 | **High** | Spurious E_FAIL or skipped gate |
| Send vtbl+0x18 + flags 0 | **High** | Wrong guarantee / wrong method |
| E_FAIL vs 0 | **High** | Callers mis-handle “not connected” |
| All 50+ sites ESI-correct | **Probable** | Rare site may use different register setup |
| Runtime verified | **Open** | Deferred |

---

## 3. Cross-check against raw + bytes

```
// ESI=client*; [esp+4]=size16; [esp+8]=buf; ret 8
if (*(ESI+0xc7c)==0) return 0x80004005;
if (!conn->vtbl[+8]()) return 0x80004005;
conn->vtbl[+0x18](-1, buf, (int)size, 0);
return 0;
```

Clean must **not** invent EAX reliability algebra, ECX thiscall, or silent null drop. Parent chat dual already routes global `0x8000` through this unit; sector `0x2021` through sibling.

---

## 4. Surviving contract for AutoCore

```
// Port of Client_SendGlobalPacket
// Register ABI: client lives in ESI at call (MSVC custom / post-setup).
// Stack: short size, void* buffer. Returns HRESULT-style.
HRESULT Client_SendGlobalPacket(Client* c, int16_t size, void* buf) {
  IConn* conn = c->globalConn; // +0xc7c
  if (!conn) return E_FAIL;           // 0x80004005
  if (!conn->IsReady()) return E_FAIL; // vtbl+0x08
  conn->Send(0xFFFFFFFF, buf, size, /*flags*/ 0); // vtbl+0x18
  return S_OK; // 0
}

// Contrast sector:
//   Client_SendSectorPacket(c, size, buf) // ECX thiscall
//   null conn → still S_OK (silent); flags from EAX bit3
```

Matches AutoCore global C2S paths that need hard fail when global net is down (chat, quit dialogs) vs sector builders that tolerate missing sector conn.

---

## 5. Open questions

1. Exact interface name for conn vtbl+8 / +0x18.
2. Whether any caller uses ECX by coincidence (bytes of **this** unit ignore ECX).
3. Mapping of hardcode flags 0 to TNL RPCGuaranteedOrdered (same domain as sector dual).
4. Runtime wire verification.

**Verdict:** Adversarial checks strengthen ESI ABI, E_FAIL policy, and sector contrast. **accept-with-gaps.**
