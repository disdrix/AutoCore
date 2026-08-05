# Review A (reconstruction fidelity): `aa_00893580` UiSelectPanel_RefreshWidget_At54c_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00893580` |
| **VA** | `0x00893580`–`0x008935b8` |
| **Canonical name** | `UiSelectPanel_RefreshWidget_At54c_Inferred` (Ghidra `FUN_00893580`) |
| **Ghidra name** | `FUN_00893580` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (OWN-ONLY dual) |
| **Counterpart** | `reviews/B_aa_00893580_UiSelectPanel_RefreshWidget_At54c_Inferred.md` |
| **System** | `interaction-activation` / client select-target UI refresh |
| **Verdict** | **accept-with-gaps** — CF, widget slot `+0x54c`, vtbl `+0xfc`, twin of `+0x520` sealed; product UI names open |
| **Dual status** | **Present (first full dual)** |

---

## 1. Purpose

Thin **select-target UI panel refresh** for the child widget pointer at **panel+0x54c**. Sole static caller: `Client_SelectTargetObject_Inferred` (`0x0093e120`) when `client+0x10b4` panel is non-null and `vfunc+0x3d8` (visible/active) is true.

Register contract from parent (decompiler `unaff_*`):

* **`EDI`** = UI panel object (`*(client + 0x10b4)`).
* **`EBX`** = selection / enable state (non-zero vs zero branch after helper).

```c
// Custom register ABI (not a clean cdecl leaf)
void UiSelectPanel_RefreshWidget_At54c_Inferred(void)
// EDI = panel*, EBX = mode/flag from select path
```

CF:

1. If `*(panel + 0x54c) == 0` → return.
2. `FUN_00837d50()` with `EAX = EBX`, `ESI = widget` (shared widget-configure helper — not dual-owned here).
3. Reload `ECX = *(panel + 0x54c)`.
4. **Always** push `0x3f000000` (**0.5f**).
5. If `EBX != 0`: `widget->vtbl[+0xfc](1)` path (stack still has 0.5f — see §3).
6. Else: `widget->vtbl[+0xfc](0, 0.5f)`.

**Sibling:** `FUN_008b2470` / `aa_008b2470` — same CF with widget at **`+0x520`** (panel `client+0x10a4`).

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Function record / raw / annotated / clean | `aa_00893580_*`, `FUN_00893580.cpp` |
| Live decompile | Ghidra `batch_decompile` `0x00893580` + helper `0x00837d50` + parent `0x0093e120` |
| Entry bytes | `read_memory` 80 B @ `0x00893580` |
| Callers | sole: `FUN_0093e120` (`Client_SelectTargetObject_Inferred`) |
| Callees | `FUN_00837d50`; indirect `vtbl+0xfc` |
| Parent dual | `A_aa_0093e120_*` lists this as UI refresh for `+0x10b4` |

**Not performed:** dual of `FUN_00837d50`; product name of vtbl `+0xfc`; runtime; Launcher.

---

## 3. Machine bytes (authoritative vs decompile asymmetry)

```
56                   push esi
8B B7 4C 05 00 00    mov  esi, [edi+0x54C]
85 F6                test esi, esi
74 2C                je   ret
8B C3                mov  eax, ebx
E8 …                 call FUN_00837d50
85 DB                test ebx, ebx
8B 8F 4C 05 00 00    mov  ecx, [edi+0x54C]
68 00 00 00 3F       push 0x3F000000          ; 0.5f — both arms
74 0C                je   zero_arm
8B 01                mov  eax, [ecx]
6A 01                push 1
FF 90 FC 00 00 00    call [eax+0xFC]
5E C3                pop  esi / ret
; zero_arm:
8B 11                mov  edx, [ecx]
6A 00                push 0
FF 92 FC 00 00 00    call [edx+0xFC]
5E C3                pop  esi / ret
```

**Notes:**

* Immediate **`0x3f000000` = +0.5f** sealed (`read_memory`).
* No `add esp` after calls → callee cleans stack args (stdcall-like on stack params; `ECX=this`).
* Live decompile shows nonzero arm as **`(1)` only** and zero arm as **`(0, 0.5f)`**. Assembly pushes **0.5f before the branch for both arms**. Prefer assembly: second stack word is present on both paths; exact consumer arity is residual (helper dual) but **0.5f is not exclusive to the zero arm**.

---

## 4. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Widget slot **`panel+0x54c`** | **Confirmed** | both loads |
| Null widget early-out | **Confirmed** | `test esi / je` |
| Shared helper `FUN_00837d50` before vfunc | **Confirmed** | call site |
| Indirect **`vtbl+0xfc`** | **Confirmed** | `call [reg+0xfc]` |
| Float **0.5f** constant | **Confirmed** | `push 0x3f000000` |
| Twin of `008b2470` (+0x520) | **Confirmed** | byte-identical except offset |
| Parent = select-target UI refresh | **High** | sole caller + dual |
| Product panel / widget English | **Open** | residual |
| Exact vfunc arity / name for `+0xfc` | **Probable** | assembly favors (flag, 0.5f); decompiler asymmetric |
| EBX semantic (“selected?”) | **Probable** | parent select path; not named in this body |

---

## 5. Control flow checklist

| Stage | Match |
|---|---|
| Null `+0x54c` skip | **Yes** |
| `00837d50` configure | **Yes** |
| Branch on EBX | **Yes** |
| `vtbl+0xfc` both arms | **Yes** |
| No network / mission / physics | **Yes** |

---

## 6. Gaps

1. Product names for panel class, widget at `+0x54c`, and `vtbl+0xfc` (enable/alpha/highlight?).
2. OWN dual of `FUN_00837d50`.
3. Seal EBX producer in all parent paths.
4. Runtime / bit-exact open.

**Verdict:** **accept-with-gaps** — select-panel widget refresh at `+0x54c` with 0.5f / `+0xfc` sealed; English + helper residual.
