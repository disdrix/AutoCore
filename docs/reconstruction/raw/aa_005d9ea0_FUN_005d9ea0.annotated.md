# Annotated low-level: Drive_CollisionListener_PrepBodyContact (FUN_005d9ea0)

| Field | Value |
|---|---|
| Stable ID | `aa_005d9ea0` |
| VA | `0x005d9ea0`–`0x005da093` (500 B) |
| Canonical | `Drive_CollisionListener_PrepBodyContact` |
| Ghidra | `FUN_005d9ea0` |
| System | drive / collision / client FX+SFX |
| Date | 2026-07-29 W25-K |

## Machine-level notes

- **thiscall RET 0x14**: ECX = CollisionListener*; five stack formals; void.
- Contact calls twice (A/B) with enable gate and per-side out flag.
- `this+0xc` caches last processed body identity (`*body`) to debounce sound on repeat.
- Pair-list scan types **1 / 3 / 4** match Contact’s type-1 GO resolve pattern.
- Impact gate **1.0f** shared with Contact UI magnitude gate (`_DAT_00af4364`).
- `PlayCollisionEffect(..., allowCreate=0)` — no lazy FxMaster from prep path.
- Decompiler types `param_5` as float but first use is **byte enable**; later reused as FPU scratch for ABS — **bytes authoritative**.

## Signature

```c
// __thiscall RET 0x14
void Drive_CollisionListener_PrepBodyContact(
    CollisionListener* this,
    void* ctx,              // Contact ctx (event+0x14); threaded to sound/FX
    int* body,              // phys body chain head
    float* impact,          // impact sample (ABS magnitude)
    uint8_t enable,         // Contact rate/material gate
    uint8_t* outPlayed);    // set 1 if collision FX path ran
```

## Pseudocode (annotated)

```c
void __thiscall PrepBodyContact(
    CollisionListener* self, void* ctx, int* body,
    float* impact, uint8_t enable, uint8_t* outPlayed)
{
  int* node = body;
  while (node[3]) node = (int*)node[3];          // walk parent chain
  int* host = (int*)node[8];
  int* go = nullptr;

  // type==1 → optional GO via flag bit5 + vtbl+0x1C8
  for (int i = 0; i < host[0x34/4]; ++i) {
    int* ent = ((int**)host[0x30/4])[i*2]; // key at pair[0]
    // decomp: *pair == 1 → value at pair[1]
    ...
  }
  int mat3 = find_pair(host, 3);  // 0 if miss
  int mat4 = find_pair(host, 4);

  bool soundDone = false;
  if (self->lastBodyAt0xC != *body) {
    if (enable) {
      float a = fabsf(*impact);
      if (a > 1.0f)
        PlayCollisionSound(ctx, &a, mat3, mat4);
      soundDone = true;
    }
    self->lastBodyAt0xC = *body;
  }

  if (go && nested_type(go) == 3) {
    auto* p3 = MaterialLookup(&scratch, 3);
    auto* p4 = MaterialLookup(&scratch, 4);
    if (enable) {
      float a = fabsf(*impact);
      if (a > 1.0f) {
        if (!soundDone)
          PlayCollisionSound(ctx, &a, *p3, *p4);
        PlayCollisionEffect(/*this*/ self, ctx, *p3, *impact, go, /*allowCreate*/ 0);
        *outPlayed = 1;
      }
      self->lastBodyAt0xC = *body;
    }
  }
}
```

## Open questions

- Exact English for pair-list types 1/3/4 and nested `+0x38 == 3`.
- ctx product type (float3* vs event cookie) — threaded identically into sound/FX.
- enable bit producers in Contact beyond raw CF.
- Runtime / bit-exact.
