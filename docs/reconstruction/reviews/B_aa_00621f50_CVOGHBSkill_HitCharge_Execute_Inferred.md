# Review B (skeptical / adversarial): `aa_00621f50` CVOGHBSkill_HitCharge_Execute_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00621f50` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` (R12-005) |
| **Counterpart** | `reviews/A_aa_00621f50_CVOGHBSkill_HitCharge_Execute_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `analyze_function_complete` + `disassemble_function` + `read_memory` + xrefs/callees/callers. No `disassemble_bytes`. No Launcher.

---

## 1. Claims under attack

| # | Claim | Result |
|---|---|---|
| 1 | Ghidra `undefined FUN_00621f50(void)` means zero formals / void return | **Falsified** — `ret 0x18`, six stack loads, `mov eax,1` |
| 2 | This unit is the OnDoHit **constructor** | **Falsified** — ctor is `FUN_00621350`; this is multi-target loop that *calls* it then upgrades vtbl |
| 3 | Class is still anonymous `FUN_*` / still OnDoHit | **Falsified as identity** — RTTI `.?AVCVOGHBSkill_HitCharge@@` on COL before vtbl `009d1624` |
| 4 | Same as OnDoHit execute `00621700` (merge) | **Falsified** — size `0x6d0` vs `0x6c0`; vtbl `009d1624` vs `009d15c4`; calls OnDoHit ctor then overwrites; zeros `+0x6c0/+0x6c4` |
| 5 | Direct call graph (many code xrefs) | **Falsified count** — sole xref is DATA `@009d1650` (vtbl dispatch) |
| 6 | Returns 0 on empty / failed resolve | **Falsified** — only exit is sentinel with **1**; miss paths continue |
| 7 | Uses instance `this` fields | **Falsified** — ECX never consumed as `this`; all state from stack args |
| 8 | Alloc size `0x6c0` like OnDoHit | **Falsified** — `push 0x6d0` |
| 9 | Enqueue list offset equals resolve ctx offset | **Falsified** — resolve `+0xe4e8`, list `+0xe4ec` |
| 10 | Decompiler `pAction[0x2b].nPeriodMs` is product field name | **Falsified as English** — bytes seal dword `+0x6c0=0` and float `+0x6c4=0.0` only; period overlay is Ghidra type noise |
| 11 | Product method name is sealed English "Execute" | **Survives only as INFERRED** — slot role family; demangle open → gaps |
| 12 | `operator_new` null path is safe | **Survives as image hazard** — null ESI then `[esi+0x18]` would fault; retail new throws / never null; decompiler path only |
| 13 | Runtime Confirmed | **Not claimed** — Terminal false; no Launcher |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Loop / sentinel / resolve CF | **High** | Wrong multi-target skill apply |
| `ret 0x18` + return 1 | **High** | Stack corruption / wrong success code |
| Class vtbl + RTTI HitCharge | **High** | Bind wrong skill subclass |
| Parent OnDoHit ctor + vtbl upgrade | **High** | Miss inheritance / size layout |
| Tail zeros `+0x6c0/+0x6c4` | **High** (bytes) | Incomplete HitCharge construction |
| Method English "Execute" | Medium / open | Naming only |
| Tail field product English | Low / open | Port field names only |
| char index wrap behavior | Low / open | Pathological huge tables |

---

## 3. Cross-check against raw + bytes

```
push 0x6d0
call operator_new
mov ecx, esi
call FUN_00621350                  ; CVOGHBSkill_OnDoHit_Ctor
xorps xmm0, xmm0
mov dword [esi], 009d1624          ; HitCharge vtbl (overwrites OnDoHit)
mov dword [esi+0x6c0], ebx         ; 0
movss dword [esi+0x6c4], xmm0      ; 0.0f
cmp dword [esi+0x18], 0
jz  dtor_path
mov ecx, [ebp+0xe4ec]
push esi
call CVOGHBList_Enqueue
mov ecx, esi
call CVOGHBBase_Start
...
mov eax, 1
ret 0x18
```

Clean must **not** claim:
- OnDoHit class identity for the *installed* vtbl (parent ctor is intermediate only).
- SpawnEntities / Virus / Master sizes or vtbls.
- Merge with `FUN_00621700` (OnDoHit execute, `0x6c0` / `009d15c4`).
- Runtime Confirmed.

---

## 4. Surviving contract for AutoCore

```csharp
// Port shape — HitCharge multi-target arm (client skill HB)
foreach (var tfid in targetTableUntilSentinel) {
    var target = ResolveObjectTarget(world.ResolveCtx /* +0xe4e8 */, tfid);
    if (target == null) continue;
    var hb = new CVOGHBSkill_HitCharge(); // retail size 0x6d0
    // CVOGHBSkill_OnDoHit_Ctor(source, skillBlob, worldAsArg4, target, tfid16, arg7)
    // install HitCharge vtbl 009d1624; zero +0x6c0 / +0x6c4
    if (hb.Owner != null) world.HbList /* +0xe4ec */.Enqueue(hb).Start();
    else hb.Delete();
}
return 1; // always on sentinel
```

Preserve **return 1** even when zero targets resolved. Preserve separate resolve vs list offsets. Preserve **0x6d0** and post-OnDoHit tail zeros.

---

## 5. Open questions

1. Product method name at vtbl+0x2C.
2. Who dispatches this slot (skill HB tick / reaction / cast pipeline) — not OWN.
3. Product English for HitCharge fields at `+0x6c0` / `+0x6c4`.
4. Whether `param_3` as OnDoHit/base ctor arg4 is world ctx by design (matches sealed parent stores).
5. Runtime / bit-exact / differential.

**Verdict:** **accept-with-gaps**
