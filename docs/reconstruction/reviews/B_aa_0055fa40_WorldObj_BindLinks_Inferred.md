# Review B (skeptical / adversarial): `aa_0055fa40` WorldObj_BindLinks_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0055fa40` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (W26-E) |
| **Counterpart** | `reviews/A_aa_0055fa40_WorldObj_BindLinks_Inferred.md` |
| **Verdict** | **accept** |

**Tools:** Ghidra `decompile_function` + `read_memory` only (plus analyze complete for xrefs).

---

## 1. Claims under attack

| # | Claim | Result |
|---|---|---|
| 1 | Decompiler `void FUN_0055fa40(int,int)` hides thiscall | **Partially true residual** — ECX is manager; second int is stack object; **ret 4** seals one formal |
| 2 | This is an unbind / remove path | **Falsified** — callers pair it **after** `0055fbf0` unbind; body attaches scale/pose |
| 3 | Scale factor is 1.0f | **Falsified** — `DAT_00a0f298` bytes `00 00 00 3F` = **0.5f** |
| 4 | Always multi-entry attach | **Falsified** — `obj+0x40==0` takes single `FUN_006297e0` |
| 5 | Function returns status in EAX | **Falsified** — void; no EAX product idiom |
| 6 | Direct network decoder caller | **Falsified** — 5 manager helpers only |
| 7 | Decompiler `FUN_0062d960(*(manager+0x234))` is full ABI | **Residual** — bytes show push field + `lea ecx,stack`; ECX is scratch not manager |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Bind role in rebind pair | **High** | Wrong lifecycle order |
| Manager thiscall + ret 4 | **High** | Stack bugs |
| 0.5f scale | **High** | Pose scale desync |
| Simple/complex gate | **High** | Missing multi-link |
| Nested helper layouts | Medium residual | Must dual those VAs separately |
| Product English | Medium | Naming only |

---

## 3. Cross-check against raw + bytes

```
push ebp; mov ebp,esp; and esp,-16; sub esp,0x64
mov ebx,[ebp+8]          ; obj
cmp dword [ebx+0xc],0
mov esi,ecx              ; manager
jz early_out
mov eax,[esi+0x234]
push eax
lea ecx,[esp+…]
call FUN_0062d960
…
pop edi; pop esi; pop ebx; mov esp,ebp; pop ebp; ret 4
```

Clean must **not** invent unbind, enroll counters, or AI switches (those belong to `0055fbf0` / `00560ec0` / `0053dbb0`).

---

## 4. Surviving contract for AutoCore

```csharp
// Port shape (world/phys manager)
void WorldObj_BindLinks(Manager mgr, WorldObj obj)
{
    if (obj.ComponentAt0x0C == null) return;
    PrepareBindScratch(mgr.Field234);
    float scale = mgr.ProfileFloatAt_CC_plus8 * 0.5f;
    var pose = obj.Block14 + 0x20;
    obj.Component.Vtbl0x18(pose, scale, outScratch);
    mgr.ComponentC4.Vtbl4(obj+0x1C, …);
    if ((int)scale > 0) {
        if (!obj.Flag40)
            AttachSimple(pose, scale);      // FUN_006297e0
        else
            AttachMultiEntry(mgr, obj, pose, scale); // FUN_006caaa0 walk
    }
    FreeLocalContainer();                   // FUN_0055f4c0
}
// Pair: UnbindLinks then BindLinks then flag — see WorldObj_RebindActivate.
```

---

## 5. Open questions

1. Whether server ghost bind needs multi-entry path parity.
2. Product meaning of `obj+0x40` shared with `0053dbb0` AI gate.
3. Full dual of unbind twin `0055fbf0` (W26-D OWN).

**Verdict:** **accept**
