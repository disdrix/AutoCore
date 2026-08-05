# Review B (skeptical / adversarial): `aa_00560f70` WorldObj_RehomeLinksFromSnapshot_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00560f70` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (W27-O) |
| **Counterpart** | `reviews/A_aa_00560f70_WorldObj_RehomeLinksFromSnapshot_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `read_memory` + call-site context. No `disassemble_bytes`. No Launcher.

---

## 1. Claims under attack

| # | Claim | Result |
|---|---|---|
| 1 | Decompiler 3-param thiscall is wrong / missing formals | **Survives** — call site **2** stack pushes + ECX; **`ret 8`** matches |
| 2 | This is only a rebind (same as `00560f30`) | **Falsified** — phases 1–3 rehome children/links/actions after phase 0 |
| 3 | Body pairs always go through `FUN_0055efd0` | **Falsified** — **open-coded** grow/store on `manager+0x20` (same policy, no CALL to `0055efd0`) |
| 4 | `unaff_EBX` is a real third stack argument | **Falsified** — storage is register; formal count is 2 stack; decompiler residual |
| 5 | Snapshot is owned by the object permanently | **Falsified as permanent** — call site passes **stack buffer** filled by `005617c0` earlier in SwitchHBAI |
| 6 | Type code `0xb` means “skip always delete” | **Not sealed** — only structural “skip pair emit when `vtbl+0x20()==0xb`” |
| 7 | Multiple external callers | **Falsified** — sole xref `005d4440` |
| 8 | Action path always calls `006292a0` | **Partial** — only when action is found in host reverse list; always still runs `vtbl+0x18` collect |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Phase 0 + ABI ret 8 | **High** | Stack / lifecycle bugs |
| Snapshot child rehome + `child+0x14` | **High** | Orphan children |
| Open-coded pair policy | **High** | Miss island glue pairs |
| Action match/push/remove | **High** | Double-own or leak reverse links |
| `unaff_EBX` virtual | **Low–Med** | Wrong secondary notify if ported literally |
| Product names | Medium | Naming only |

---

## 3. Cross-check against raw + bytes + call site

```
; entry: sub esp,30h; push ebx; mov ebx,[esp+38h]  ; first stack after frame = obj
; ... flag at [esi+12Ch] ...
; epilogue: add esp,30h; ret 8
```

Clean must keep **open-coded** pair writes (not invent a call to `0055efd0`).  
Clean must **not** treat `unaff_EBX` as a formal.  
Port must free/return arena the same way (`DAT_00b05060` paths).

Sibling trap: `00561580` is a **different** host detach/reattach path (also calls action helpers) — not this VA.

---

## 4. Surviving contract for AutoCore

```csharp
// Port shape — mode-exit-7 rehome (after snapshot captured)
void WorldObj_RehomeLinksFromSnapshot(Manager mgr, WorldObj obj, Snapshot snap)
{
    WorldObj_ReattachLinksGuarded(mgr, obj); // phase 0

    var host = obj.HostAt0x44;
    foreach (var child in snap.Items) {
        HostChildListPush(host, child);      // +0x58 growable
        child.NotifyAfterPush(...);          // vtbl+0x28 + residual virtual
        child.Field14 = host;
    }

    foreach (var link in obj.LinksAt0x88) {
        if (link.GetTypeCode() == 0x0B) continue; // vtbl+0x20
        // emit body pair(s) onto mgr.PairListAt0x20 when +0x40 clear
    }

    foreach (var action in obj.ActionsAt0x94) {
        if (HostReverseListContains(mgr.SubAt0x2c, action)) {
            HostActionListPush(host, action);   // 006292a0
            RemoveReverseListEntry(...);        // 00628f10
            action.OwnerAt0x10 = host;
        }
        var neighbors = action.CollectBodies(); // vtbl+0x18
        // pair each other body with +0x40==0 against obj
    }
}
```

---

## 5. Open questions

1. What mode code **7** is in product terms (and why only that mode needs snapshot rehome).
2. Exact type of the second virtual after `vtbl+0x28`.
3. Whether server ghost/phys needs the same rehome on AI mode switch.
4. Dual seal of `005617c0` snapshot producer (not OWN).

**Verdict:** **accept-with-gaps**
