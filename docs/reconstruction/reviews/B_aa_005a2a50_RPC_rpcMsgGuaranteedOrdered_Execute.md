# Review B (skeptical / adversarial): `aa_005a2a50` RPC_rpcMsgGuaranteedOrdered_Execute

| Field | Value |
|---|---|
| **Stable ID** | `aa_005a2a50` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_005a2a50_RPC_rpcMsgGuaranteedOrdered_Execute.md` |
| **Verdict** | **accept** on body contract; **accept-with-gaps** on name→scope |

---

## 1. Claims under attack

| # | Claim | Attack / outcome |
|---|---|---|
| 1 | Function “executes” GuaranteedOrdered RPC payload | **Falsified** — body is type-check only; no pack/unpack/dispatch of message bytes |
| 2 | Name implies GuaranteedOrdered-only | **Overstated** — shared by **6** DATA slots; reliability not encoded in body |
| 3 | `param_1` is “uint32 width” production type | **Overstated** — pointer to `TNL::Object` / connection; decompiler width is 4 |
| 4 | cdecl / thiscall | **Falsified** — `ret 4` = **stdcall**, single stack arg |
| 5 | Returns cast pointer | **Falsified** — returns **bool** 0/1 via neg/sbb/neg, not the casted pointer |
| 6 | Has code callers that invoke it directly | **Falsified** — zero code xrefs; only vtable DATA |
| 7 | AutoCore `CheckClassType` is wrong | **Not supported** — C# `(obj as TNLConnection) != null` is semantic twin of this cast |
| 8 | Runtime verified | **Open** — deferred; pure CRT RTTI path low risk |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Pure type gate | High | Wrong → invent fake payload logic in port |
| Target class TNLConnection | High | Wrong → accept wrong connection subclass |
| Source class TNL::Object | High | Wrong → RTTI path mis-modeled |
| Shared across 6 event vtbls | High | Wrong → duplicate Execute per reliability class |
| Name is symbol/scaffold, not scope seal | High | Wrong → assume only Ordered uses this body |
| AutoCore CheckClassType parity | High | Low — already matches |
| Which vtbl row is which RPC class | Medium | Wrong labeling only; not body semantics |

---

## 3. Surviving contract for AutoCore

```text
// Native VA 0x005a2a50 — TNL RPCEvent Execute / CheckClassType
bool RPC_rpcMsgGuaranteedOrdered_Execute(TNL::Object *obj)  // stdcall
{
    return __RTDynamicCast(obj, 0,
        &TNL::Object::RTTI,          // 0x00b00ba4  ".?AVObject@TNL@@"
        &TNLConnection::RTTI,        // 0x00af3a48  ".?AVTNLConnection@@"
        0) != nullptr;
}

// Called only via NetEvent vtable Execute slots (DATA @ 0x009d7c84 + i*0x30, i=0..5).
// On true → Functor.Dispatch(connection); on false → skip (TNL RPCEvent.Process).
```

**Port rule:** Keep AutoCore’s six `RPCMsg*` classes’ `CheckClassType` as `(obj as TNLConnection) != null`. Do **not** attach reliability or opcode logic to this unit.

**Do not confuse with:**
- `Client_SendSectorPacket` reliability flags (`RPCGuaranteedOrdered = 0`) — transport selection, different VA.
- `rpcMsgGuaranteedOrdered_remote` / `HandlePacket` — actual payload path after CheckClassType succeeds.

---

## 4. Open questions

1. Exact mapping of six vtable bases → Guaranteed / Ordered / NonGuaranteed ± Fragmented (Method1 + string xrefs; sibling units).
2. Whether client and server share this same Execute body image (same EXE).
3. Failure-mode observability when cast fails (silent skip vs assert) — owned by TNL Process, not this VA.

**Verdict:** **accept** as sealed CheckClassType / Execute type gate; **accept-with-gaps** only for GuaranteedOrdered-centric naming vs multi-vtable sharing. Safe behavioral map for AutoCore TNL ports.
