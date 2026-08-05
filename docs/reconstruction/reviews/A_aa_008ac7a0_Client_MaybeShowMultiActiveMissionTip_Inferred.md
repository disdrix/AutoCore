# Review A (reconstruction fidelity): `aa_008ac7a0` Client_MaybeShowMultiActiveMissionTip_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_008ac7a0` |
| **VA** | `0x008ac7a0`–`0x008ac884` (228 B) |
| **Canonical name** | `Client_MaybeShowMultiActiveMissionTip_Inferred` |
| **Ghidra name** | `FUN_008ac7a0` |
| **Review date** | `2026-08-04` |
| **Reviewer role** | Independent reconstruction review (OWN-ONLY dual WQ7R-A) |
| **Counterpart** | `reviews/B_aa_008ac7a0_Client_MaybeShowMultiActiveMissionTip_Inferred.md` |
| **System** | `missions-progression` |
| **Verdict** | **accept-with-gaps** |
| **Dual status** | **Present (first full dual)** |

**Tools:** Ghidra `decompile_function` + `analyze_function_complete` + `read_memory` + callers/xrefs. **No** `disassemble_bytes`. No Launcher.

---

## 1. Purpose

Post-accept helper: under HashError traversal lock, count active-mission hash payloads that pass `short@+0xf8==0 && int@+0xfc!=-1`; if count ≥ 2, invoke `Client_MaybeShowFirstTimeTip(0x20)`. No network, no hash mutation beyond the lock byte, no dialog chrome.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Live decompile | Ghidra `decompile_function` `0x008ac7a0` (2026-08-04) |
| Body bounds | `get_function_by_address` → `008ac7a0`–`008ac884` |
| Entry bytes | `read_memory` 240 B @ `0x008ac7a0` |
| Callers | `get_function_callers` → sole `Client_MissionDialogHandleButton` |
| Xref | call site `0x008aec20` |
| Raw | `docs/reconstruction/raw/aa_008ac7a0_FUN_008ac7a0.md` |
| Annotated | `docs/reconstruction/raw/aa_008ac7a0_FUN_008ac7a0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Client_MaybeShowMultiActiveMissionTip_Inferred.cpp` |
| Function records | `functions/aa_008ac7a0_FUN_008ac7a0.md`, named twin |
| Parent accept path | `Client_MissionDialogHandleButton.cpp` (GiveMission → tip2 → this) |
| Tip dual | `A_aa_00801760_Client_MaybeShowFirstTimeTip` |
| System map | `systems/missions-progression.md` (`+0x540` active missions) |

**Not performed:** Launcher, tip-string table dump, payload type dual (parent residual).

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Body 228 B / end `008ac884` | **Confirmed** | `get_function_by_address` |
| No-arg plain `ret` (`C3`) | **Confirmed** | epilogue bytes |
| Gate: `DAT_00d1b6d8!=0` and `(+0xd34)&1==0` | **Confirmed** | decomp ≡ entry bytes |
| Hash root `+0x540` | **Confirmed** | decomp + missions map |
| Lock byte `hash+0x1d` set/clear | **Confirmed** | decomp + HashError strings |
| Walk `hash+0x14` / `node+0x14`, payload `node+8` | **Confirmed** | decomp ≡ bytes |
| Count iff `short(+0xf8)==0 && int(+0xfc)!=-1` | **Confirmed** | `cmp word` / `cmp dword,-1` |
| Tip when count ≥ 2 | **Confirmed** | `cmp ebx,2` / `jl` + decomp `1 < iVar2` |
| Tip id `0x20`, this `DAT_00d1a840` | **Confirmed** | `push 0x20` / `mov ecx,00d1a840` |
| Sole caller accept path | **Confirmed** | xrefs + parent clean |
| Not list refresh / not C2S | **Confirmed** | no send callees |
| Product tip English / field names | **Open** | `_Inferred` |
| `+0xd34` bit0 ≡ tip-0x20 FirstFlags bit | **Probable** | co-located with tip map formula; not re-proven object base |
| Runtime / bit-exact | **Open** | terminal false |

---

## 4. Control flow checklist

| Stage | Match |
|---|---|
| Singleton null → return | Yes |
| `+0xd34` bit0 set → return | Yes |
| TraversalLock enter (+ optional HashError) | Yes |
| Linked walk until payload null | Yes |
| Conditional count | Yes |
| Unlock | Yes |
| count≥2 → MaybeShowFirstTimeTip(0x20) | Yes |
| No other side effects | Yes |

### Recovered CF

```c
void Client_MaybeShowMultiActiveMissionTip_Inferred(void)
{
    if (!DAT_00d1b6d8 || (*(uint8_t*)(DAT_00d1b6d8 + 0xd34) & 1)) return;
    // lock hash@+0x540 +0x1d
    // for node in chain: payload=node+8;
    //   if payload && *(short*)(p+0xf8)==0 && *(int*)(p+0xfc)!=-1: count++;
    // unlock
    // if count >= 2: Client_MaybeShowFirstTimeTip(DAT_00d1a840, 0x20);
}
```

---

## 5. Gaps

1. Product / PDB symbol (name is role-inferred).
2. English for tip `0x20` and payload `+0xf8` / `+0xfc`.
3. Full type of hash payload object.
4. Independent proof that gate bit is exclusively tip-0x20 FirstFlags.
5. Runtime / bit-exact.

**Verdict:** **accept-with-gaps** — CF, ABI, call surface, count predicate, tip threshold sealed; product English open.
