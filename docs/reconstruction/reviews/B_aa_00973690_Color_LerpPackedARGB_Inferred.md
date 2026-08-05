# Review B (skeptical / adversarial): `aa_00973690` Color_LerpPackedARGB_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00973690` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (W28-F) |
| **Counterpart** | `reviews/A_aa_00973690_Color_LerpPackedARGB_Inferred.md` |
| **Verdict** | **accept** |

**Tools:** Ghidra `decompile_function` + `read_memory` + call-site context. No `disassemble_bytes`. No Launcher.

---

## 1. Claims under attack

| # | Claim | Result |
|---|---|---|
| 1 | Surface `void FUN(float,uint,uint)` is full ABI | **Partial** — missing **ECX dest** and **`ret 0x0C`**; sealed from bytes + sites |
| 2 | This is a matrix helper (W27-F open English as "matrix") | **Falsified** — pure color lerp; matrix work is sibling `FUN_00973820` |
| 3 | Result returned in EAX as packed dword | **Falsified** — writes through **dest pointer**; void return |
| 4 | Channels are float 0..1 normalized | **Falsified** — 0..255 integer channels; pack helper clamps |
| 5 | `t` is unclamped | **Falsified** — [0,1] via 0.0 / `g_flOne` |
| 6 | More than 3 callers | **Falsified** — exactly **3** code xrefs |
| 7 | Lerp uses float channel subtract without int cast | **Falsified** — retail uses `(int)` delta then float |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| ECX dest + ret 0x0C | **High** | Stack corruption / wrong write target |
| Clamp + channel lerp CF | **High** | Wrong tint at 0.75 motion path |
| 0xAARRGGBB layout | **High** | Swapped R/B in port |
| Product name | Medium | Naming only |
| `FUN_00973590` internals | Out of scope | Must not invent pack rules beyond dual |

---

## 3. Cross-check against raw + bytes + call sites

```
; 004b18f0 site (ObjectMotion_SyncChildPoseHF):
MOV  EAX, [ESI+8]          ; child
MOV  EDX, [EAX+0x34]       ; c0
LEA  ECX, [EAX+0x34]       ; dest = same slot
MOV  EAX, [0x00afdef0]     ; c1 = 0xFF000000
PUSH EAX / PUSH EDX / PUSH 0x3f400000  ; c1, c0, t=0.75
CALL 00973690              ; ret 0x0C
```

Clean must **not** invent a returned color in EAX, skip clamp, or treat formals as cdecl without cleanup.

---

## 4. Surviving contract for AutoCore

```csharp
// Port shape — graphics color
void Color_LerpPackedARGB(ref uint dest, float t, uint c0, uint c1)
{
    t = Math.Clamp(t, 0f, 1f);
    // per-channel: (int)(ch1-ch0)*t + ch0  as float, then pack 0xAARRGGBB
    dest = PackARGB(LerpCh(c0, c1, t));
}
// In-place dest; three stack args cleaned by callee (stdcall-12).
```

---

## 5. Open questions

1. Whether server needs this (likely client-render only).
2. Dual seal of `FUN_00973590` when scheduled.
3. Exact SSE rounding vs C `float` cast on all platforms.

**Verdict:** **accept**
